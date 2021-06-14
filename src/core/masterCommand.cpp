// This file is part of SonarPhony.
//
// SonarPhony is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SonarPhony is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SonarPhony.  If not, see <http://www.gnu.org/licenses/>.

#include <yart/core/masterCommand.h>
#include <yart/core/msgPrivate.h>

using namespace sonarphony;


///////////////////////////////////////////////////////////////////////////
namespace
{

/// \brief Total message size
unsigned const MESSAGE_SIZE     = 71;

/// \brief Magical header data
unsigned char const HEADER[] = {
	0x46, 0x43, 0x15, 0x00, 0x2c, 0x01
};

/// \brief Magical middle data
unsigned char const MAGIC_MIDDLE[] = {
	0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00
};

/// \brief Magical footer
unsigned char const FOOTER[] = {
	0x00, 0x58, 0xa2, 0xb5, 0x78, 0xef, 0xf5, 0x00, 0x00
};

}


///////////////////////////////////////////////////////////////////////////
masterCommandBuilder_t::~masterCommandBuilder_t ()
{
}

masterCommandBuilder_t::masterCommandBuilder_t () :
	m_buffer (),
	m_minRange (0),
	m_maxRange (0)
{
	m_buffer.reserve (MESSAGE_SIZE);
}

void masterCommandBuilder_t::setRange (unsigned min_, unsigned max_)
{
	Q_ASSERT (max_ <= 240);
	Q_ASSERT (min_ < max_ || min_ == 0);

	m_minRange = min_;
	m_maxRange = max_;
}

QByteArray const &masterCommandBuilder_t::build ()
{
	m_buffer.clear ();

	// Add magic header
	m_buffer.append (_U2S (HEADER), sizeof (HEADER));

	// Encode minimum range
	m_buffer.append (static_cast<char> (m_minRange));
	// Encode zeros between. It is possible this is the upper byte of the
	// max range, however since none of the available hardware is rated for
	// more than 240 ft (0xF0, 1 byte's worth), I don't know if this is the
	// case and so haven't been able to verify this.
	m_buffer.append (char (0));
	// Encode maximum range
	m_buffer.append (static_cast<char> (m_maxRange));

	// Don't know what any of this is yet
	m_buffer.append (_U2S (MAGIC_MIDDLE), sizeof (MAGIC_MIDDLE));

	// Checksum. Why that's needed inside of a UDP packet I'll never know
	m_buffer.append (calculateChecksum (m_buffer));

	// Magical message footer
	m_buffer.append (_U2S (FOOTER), sizeof (FOOTER));

	return m_buffer;
}

