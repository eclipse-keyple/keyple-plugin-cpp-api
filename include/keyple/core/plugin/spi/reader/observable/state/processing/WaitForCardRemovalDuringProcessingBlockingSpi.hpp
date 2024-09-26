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
 * Reader able to detect a card removal during processing, between two APDU
 * commands.
 *
 * <p>A typical example of readers conforming to this mode of operation are PC/SC type readers.
 *
 * @since 2.0.0
 * @deprecated Useless SPI, don't implement it. Will be removed in a future
 * version of this API.
 */
class WaitForCardRemovalDuringProcessingBlockingSpi {
public:
    /**
     *
     */
    virtual ~WaitForCardRemovalDuringProcessingBlockingSpi() = default;

    /**
     * Waits indefinitely for a card to be removed.
     *
     * <p>This wait can be cancelled for an internal (for example timeout) or
     * external reason (for example invocation of {@link
     * #stopWaitForCardRemovalDuringProcessing()}), in this case an exception is
     * raised.
     *
     * @throw ReaderIOException If the communication with the reader
     * @throw TaskCanceledException If the task has been canceled and is no
     * longer active
     * @since 2.0.0
     * @deprecated
     */
    virtual void waitForCardRemovalDuringProcessing() = 0;

    /**
     * Interrupts the waiting of the removal of the card
     *
     * @since 2.0.0
     * @deprecated
     */
    virtual void stopWaitForCardRemovalDuringProcessing() = 0;
};

} /* namespace processing */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
