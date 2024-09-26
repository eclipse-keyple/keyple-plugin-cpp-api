/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

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
 * Reader able to communicate with smart cards whose purpose is to remain
 * present in the reader (for example a SAM reader).
 *
 * <p>The target devices must comply with the following Calypsonet Terminal
 * requirements:
 *
 * <ul>
 *   <li>RL-CL-TS16794 (for contactless communication)
 *   <li>RL-DET-PCIBLOCK.1 (for contactless communication)
 *   <li>RL-CT-T0 (for contact communication)
 *   <li>RL-PERF-TIME.1
 * </ul>
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
     * Validates the opening of the physical channel. Performs the actual
     * opening if this has not been done by the checkCardPresence() method. In
     * all cases, memorizes the new state for the operation of the
     * isPhysicalChannelOpen() method. After executing this method, the reader
     * is able to send APDUs to the card.
     *
     * @throw ReaderIOException If the communication with the reader has failed.
     * @throw CardIOException If the communication with the card has failed.
     * @since 2.0.0
     */
    virtual void openPhysicalChannel() = 0;

    /**
     * Tells the reader that card processing is complete and that the next step
     * is to remove the card from the reader.
     *
     * <p>If the reader has the ability to sense the presence of the card
     * without communicating with it, then this method must proceed to the
     * actual closing of the physical channel (e.g. power down in the case of a
     * contact reader). Otherwise, this method is limited to changing the
     * logical opening state of the physical channel and letting the removal
     * procedure do the closing.
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
     * <p>Depending on the reader's capabilities, this method will either use a
     * card presence indicator without necessarily communicating with the card
     * (for example, in the case of a contact reader equipped with a physical
     * insertion detector using a switch), or will communicate with the card (in
     * the case of contactless hunting). In the latter case, we can consider
     * that the physical channel has been opened (and therefore no longer needs
     * to be opened in the openPhysicalChannel() method).
     *
     * @return True if a card is present
     * @throw ReaderIOException If the communication with the reader has failed.
     * @since 2.0.0
     */
    virtual bool checkCardPresence() = 0;

    /**
     * Gets the power-on data.
     *
     * <p>The power-on data is defined as the data retrieved by the reader when
     * the card is inserted.
     *
     * <p>In the case of a contact reader, this is the Answer To Reset data
     * (ATR) defined by ISO7816.
     *
     * <p>In the case of a contactless reader, the reader decides what this data
     * is. Contactless
     * readers provide a virtual ATR (partially standardized by the PC/SC standard), but other
     * devices can have their own definition, including for example elements
     * from the anti-collision stage of the ISO14443 protocol (ATQA, ATQB, ATS,
     * SAK, etc).
     *
     * @return A not empty array
     * @since 2.0.0
     */
    virtual const std::string getPowerOnData() const = 0;

    /**
     * Transmits an APDU and returns its response.
     *
     * <p><b>Caution: the implementation must handle the case where the card
     * response is 61xy and execute the appropriate get response command
     * (Calypsonet Terminal requirement
     * "RL-SW-61XX.1").</b>
     *
     * @param apduIn The data to be sent to the card.
     * @return A buffer of at least 2 bytes.
     * @throw ReaderIOException If the communication with the reader has failed.
     * @throw CardIOException If the communication with the card has failed.
     * @since 2.0.0
     */
    virtual const std::vector<uint8_t>
    transmitApdu(const std::vector<uint8_t>& apduIn) = 0;

    /**
     * Tells if the reader is a contactless type.
     *
     * C++ note: this function cannot be set 'const' as some derived classes
     * will set internal flags accordingly.
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
    friend std::ostream&
    operator<<(std::ostream& os, std::shared_ptr<ReaderSpi> rs) {
        (void)rs;

        os << "TODO";

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(
        std::ostream& os, const std::vector<std::shared_ptr<ReaderSpi>>& rss) {
        os << "READER_SPIS: {";

        for (auto it = std::begin(rss); it != std::end(rss); ++it) {
            os << *it;
            if (it != rss.end() - 1) {
                os << ", ";
            }
        }

        os << "}";

        return os;
    }
};

} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
