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
namespace processing {

/**
 * Reader able to detect and notify a card removal during processing, between
 * two APDU commands.
 *
 * <p>A typical example of readers conforming to this mode of operation are PC/SC type readers.
 *
 * @since 2.3.0
 */
class CardPresenceMonitorBlockingSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardPresenceMonitorBlockingSpi() = default;

    /**
     * Monitors the card presence indefinitely (the method is blocking as long
     * as the card is present).
     *
     * <p>This monitoring can be cancelled for an internal (for example timeout)
     * or external reason (for example invocation of
     * stopCardPresenceMonitoringDuringProcessing()), in this case an exception
     * is raised.
     *
     * @throw ReaderIOException If the communication with the reader has failed.
     * @throw TaskCanceledException If the task has been canceled and is no
     * longer active.
     * @since 2.3.0
     */
    virtual void monitorCardPresenceDuringProcessing() = 0;

    /**
     * Interrupts the monitoring of the card presence.
     *
     * @since 2.3.0
     */
    virtual void stopCardPresenceMonitoringDuringProcessing() = 0;
};

} /* namespace processing */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
