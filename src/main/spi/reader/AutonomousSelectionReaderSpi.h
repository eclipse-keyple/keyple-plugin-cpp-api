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
#include <string>
#include <vector>

/* Keyple Core Plugin */
#include "ReaderSpi.h"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {

/**
 * Reader having an autonomous mechanism to select the cards (for example OMAPI readers).
 *
 * @since 2.0.0
 */
class AutonomousSelectionReaderSpi : public ReaderSpi {
public:
    /**
     * 
     */
    virtual ~AutonomousSelectionReaderSpi() = default;
    
    /**
     * Opens a logical channel for the provided AID
     *
     * <p>The <b>aid</b> is provided as a byte array. It can be set to null to activate the basic
     * channel opening defined by the OMAPI.<br>
     * The bit mask indicates the ISO defined condition to retrieve the selection data.
     *
     * @param aid The AID (optional)
     * @param isoControlMask The bit mask from the ISO 7816-4 standard
     * @return A not empty byte array containing the card answer to selection
     * @throw ReaderIOException If the communication with the reader has failed.
     * @throw CardIOException If the communication with the card has failed.
     * @since 2.0.0
     */
    virtual std::vector<uint8_t> openChannelForAid(const std::vector<uint8_t> aid,
                                                   const uint8_t isoControlMask) = 0;

    /**
     * Closes the logical channel explicitly.
     *
     * @since 2.0.0
     */
    virtual void closeLogicalChannel() = 0;
};

}
}
}
}
}
