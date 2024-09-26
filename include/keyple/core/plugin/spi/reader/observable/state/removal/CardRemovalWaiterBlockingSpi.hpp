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
 * This SPI is specifically designed for plugins that handle card removal
 * synchronously. The plugin waits autonomously and indefinitely for the removal
 * of a card by implementing a waiting mechanism.
 *
 * <p>A typical example of readers conforming to this mode of operation are PC/SC type readers
 * capable of performing RF polling without waiting for a command from the
 * application.
 *
 * @since 2.2.0
 */
class CardRemovalWaiterBlockingSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardRemovalWaiterBlockingSpi() = default;

    /**
     * Waits indefinitely for a card to be removed.
     *
     * <p>This wait can be cancelled for an internal (for example timeout) or
     * external reason (for example invocation of stopWaitForCardRemoval()), in
     * this case an exception is raised.
     *
     * @throws ReaderIOException If the communication with the reader
     * @throws TaskCanceledException If the task has been canceled and is no
     * longer active
     * @since 2.2.0
     */
    virtual void waitForCardRemoval() = 0;

    /**
     * Interrupts the waiting of the removal of the card
     *
     * @since 2.2.0
     */
    virtual void stopWaitForCardRemoval() = 0;
};

} /* namespace removal */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
