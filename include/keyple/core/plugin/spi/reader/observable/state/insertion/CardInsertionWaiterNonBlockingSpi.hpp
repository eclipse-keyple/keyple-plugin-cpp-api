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
namespace insertion {

/**
 * This SPI is specifically designed for plugins that don't handle card
 * insertion autonomously but requires an external active stimulation to detect
 * card insertion without implementing a waiting mechanism.
 *
 * <p>When a plugin implements this SPI, the
 * keyple::core::plugin::spi::reader::ReaderSpi#checkCardPresence} method will
 * be called periodically by the service when a card insertion is expected.
 *
 * <p>The value returned by the getCardInsertionMonitoringSleepDuration() will
 * be used as an argument to Thread::sleep(long) between two calls to
 * keyple::core::plugin::spi::reader::ReaderSpi#checkCardPresence}.
 *
 * <p>A typical example of readers conforming to this mode of operation are
 * terminals embedding a slave RF communication module.
 *
 * @since 2.2.0
 */
class CardInsertionWaiterNonBlockingSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardInsertionWaiterNonBlockingSpi() = default;

    /**
     * Provides the value of the sleep duration (in milliseconds) inserted
     * between two calls to
     * keyple::core::plugin::spi::reader::ReaderSpi::checkCardPresence.
     *
     * @return A positive value (0 is allowed).
     * @since 2.2.0
     */
    virtual int getCardInsertionMonitoringSleepDuration() const = 0;
};

} /* namespace insertion */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
