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

#include "keyple/core/plugin/spi/reader/ReaderSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {
namespace observable {

/**
 * Reader able to detect the insertion and removal of cards.
 *
 * <p>In addition, an observable reader must also define its observation
 * capabilities for the card insertion and removal steps.
 *
 * <p>For the card insertion state, it must implement one of the following
 * interfaces:
 *
 * <ul>
 *   <li>CardInsertionWaiterAsynchronousSpi
 *   <li>CardInsertionWaiterBlockingSpi
 *   <li>CardInsertionWaiterNonBlockingSpi
 * </ul>
 *
 * <p>For the card removal state, it must implement one of the following
 * interfaces:
 *
 * <ul>
 *   <li>CardRemovalWaiterAsynchronousSpi
 *   <li>CardRemovalWaiterBlockingSpi
 *   <li>CardRemovalWaiterNonBlockingSpi
 * </ul>
 *
 * @since 2.0.0
 */
class ObservableReaderSpi : virtual public ReaderSpi {
public:
    /**
     * Invoked when the card observation process is started
     *
     * @since 2.0.0
     */
    virtual void onStartDetection() = 0;

    /**
     * Invoked when the card observation process is stopped
     *
     * @since 2.0.0
     */
    virtual void onStopDetection() = 0;
};

} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
