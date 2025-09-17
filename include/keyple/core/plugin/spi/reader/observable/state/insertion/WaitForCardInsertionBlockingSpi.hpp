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
 * Reader able to wait autonomously and indefinitely for the insertion of a card
 * by implementing a waiting mechanism.
 *
 * <p>A typical example of readers conforming to this mode of operation are PC/SC type readers
 * capable of performing RF polling without waiting for a command from the
 * application.
 *
 * @since 2.0.0
 * @deprecated Implement CardInsertionWaiterBlockingSpi instead (will be removed
 * in a future version of this API).
 */
class WaitForCardInsertionBlockingSpi {
public:
    /**
     * Waits indefinitely for a card to be inserted.
     *
     * <p>This wait can be cancelled for an internal (for example timeout) or
     * external reason (for example invocation of {@link
     * #stopWaitForCardInsertion()}), in this case an exception is raised.
     *
     * @throw ReaderIOException If the communication with the reader has failed.
     * @throw TaskCanceledException If the task has been canceled and is no
     * longer active
     * @since 2.0.0
     * @deprecated
     */
    virtual void waitForCardInsertion() = 0;

    /**
     * Interrupts the waiting of a card insertion.
     *
     * @since 2.0.0
     * @deprecated
     */
    virtual void stopWaitForCardInsertion() = 0;
};

} /* namespace insertion */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
