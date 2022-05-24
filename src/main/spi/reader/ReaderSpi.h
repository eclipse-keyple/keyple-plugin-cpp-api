/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * See the NOTICE file(s) distributed with this work for additional information regarding         *
 * copyright ownership.                                                                           *
 *                                                                                                *
 * This program and the accompanying materials are made available under the terms of the Eclipse  *
 * Public License 2.0 which is available at http://www.eclipse.org/legal/epl-2.0                  *
 *                                                                                                *
 * SPDX-License-Identifier: EPL-2.0                                                               *
 **************************************************************************************************/

#pragma once

#include <cstdint>
#include <list>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {

/**
 * Reader able to communicate with smart cards whose purpose is to remain present in the reader (for
 * example a SAM reader).
 *
 * @since 2.0.0
 */
class ReaderSpi {
public:
    /**
     * 
     */
    virtual ~ReaderSpi() = default;
    
    /**
     * Gets the name of the reader.
     *
     * @return A not empty string.
     * @since 2.0.0
     */
    virtual const std::string& getName() const = 0;

    /**
     * Attempts to open the physical channel (to established a communication with the card).
     *
     * @throw ReaderIOException If the communication with the reader has failed.
     * @throw CardIOException If the communication with the card has failed.
     * @since 2.0.0
     */
    virtual void openPhysicalChannel() = 0;

    /**
     * Attempts to close the current physical channel.
     *
     * <p>The physical channel may have been implicitly closed previously by a card withdrawal.
     *
     * @throw ReaderIOException If the communication with the reader has failed.
     * @since 2.0.0
     */
    virtual void closePhysicalChannel() = 0;

    /**
     * Tells if the physical channel is open or not.
     *
     * @return True is the physical channel is open, false if not.
     */
    virtual bool isPhysicalChannelOpen() const = 0;

    /**
     * Verifies the presence of a card.
     *
     * @return True if a card is present
     * @throw ReaderIOException If the communication with the reader has failed.
     * @since 2.0.0
     */
    virtual bool checkCardPresence() = 0;

    /**
     * Gets the power-on data.
     *
     * <p>The power-on data is defined as the data retrieved by the reader when the card is
     * inserted.
     *
     * <p>In the case of a contact reader, this is the Answer To Reset data (ATR) defined by
     * ISO7816.
     *
     * <p>In the case of a contactless reader, the reader decides what this data is. Contactless
     * readers provide a virtual ATR (partially standardized by the PC/SC standard), but other
     * devices can have their own definition, including for example elements from the anti-collision
     * stage of the ISO14443 protocol (ATQA, ATQB, ATS, SAK, etc).
     *
     * @return A not empty array
     * @since 2.0.0
     */
    virtual const std::string getPowerOnData() const = 0;

    /**
     * Transmits an APDU and returns its response.
     *
     * <p><b>Caution: the implementation must handle the case where the card response is 61xy and
     * execute the appropriate get response command.</b>
     *
     * @param apduIn The data to be sent to the card.
     * @return A buffer of at least 2 bytes.
     * @throw ReaderIOException If the communication with the reader has failed.
     * @throw CardIOException If the communication with the card has failed.
     * @since 2.0.0
     */
    virtual const std::vector<uint8_t> transmitApdu(const std::vector<uint8_t>& apduIn) = 0;

    /**
     * Tells if the reader is a contactless type.
     *
     * C++ note: this function cannot be set 'const' as some derived classes will set internal
     *           flags accordingly.
     *
     * @return True if the reader a contactless type, false if not
     * @since 2.0.0
     */
    virtual bool isContactless() = 0;

    /**
     * Invoked when unregistering the associated plugin.
     *
     * @since 2.0.0
     */
    virtual void onUnregister() = 0;

    /**
     * 
     */
    friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<ReaderSpi> rs)
    {
        (void)rs;
        
        os << "TODO";

        return os;
    }

    /**
     * 
     */
    friend std::ostream& operator<<(std::ostream& os,
                                    const std::vector<std::shared_ptr<ReaderSpi>>& rss)
    {
        os << "READER_SPIS: {";

        for (auto it = std::begin(rss); it != std::end(rss); ++it) {
            os << *it;
            if (it != rss.end()) {
                os << ", ";
            }
        }

        os << "}";

        return os;   
    }
};



}
}
}
}
}
