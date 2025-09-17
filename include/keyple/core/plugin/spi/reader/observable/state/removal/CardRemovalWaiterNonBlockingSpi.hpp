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

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {
namespace observable {
namespace state {
namespace removal {

/**
 * This SPI is specifically designed for plugins that don't handle card removal
 * autonomously but requires the sending of an APDU to detect the card removal.
 *
 * <p>When a plugin implements this SPI, the
 * keyple::core::plugin::spi::reader::ReaderSpi::transmitApdu(byte[]) method
 * will be called periodically by the service when a card removal is expected.
 * The card is considered removed when the transmission fails.
 *
 * <p>The value returned by the getCardRemovalMonitoringSleepDuration() will be
 * used as an argument to Thread::sleep(long) between two calls to
 * keyple::core::plugin::spi::reader::ReaderSpi::transmitApdu}.
 *
 * <p>A typical example of readers conforming to this mode of operation are
 * terminals embedding a slave RF communication module without card presence
 * feature.
 *
 * @since 2.2.0
 */
class CardRemovalWaiterNonBlockingSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardRemovalWaiterNonBlockingSpi() = default;

    /**
     * Provides the value of the sleep duration (in milliseconds) inserted
     * between two calls to
     * keyple::core::plugin::spi::reader::ReaderSpi::transmitApdu}.
     *
     * @return A positive value (0 is allowed).
     * @since 2.2.0
     */
    virtual int getCardRemovalMonitoringSleepDuration() const = 0;
};

} /* namespace removal */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
