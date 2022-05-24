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

/* Plugin */
#include "ReaderSpi.h"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {
namespace observable {

using namespace keyple::core::plugin::spi::reader;

/**
 * Reader able to detect the insertion and removal of cards.
 *
 * <p>In addition, an observable reader must also define its observation capabilities for the card
 * insertion, processing and removal steps.
 *
 * <p>For the card insertion state, it must implement one of the following interfaces:
 *
 * <ul>
 *   <li>{@link WaitForCardInsertionBlockingSpi}
 *   <li>{@link WaitForCardInsertionNonBlockingSpi}
 *   <li>{@link WaitForCardInsertionAutonomousSpi}
 * </ul>
 *
 * <p>For the card processing state, it must implement one of the following interfaces:
 *
 * <ul>
 *   <li>{@link WaitForCardRemovalDuringProcessingBlockingSpi}
 *   <li>{@link DontWaitForCardRemovalDuringProcessingSpi}
 * </ul>
 *
 * <p>For the card removal state, it must implement one of the following interfaces:
 *
 * <ul>
 *   <li>{@link WaitForCardRemovalBlockingSpi}
 *   <li>{@link WaitForCardRemovalNonBlockingSpi}
 *   <li>{@link WaitForCardRemovalAutonomousSpi}
 * </ul>
 *
 * @since 2.0.0
 */
class ObservableReaderSpi : public virtual ReaderSpi {
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

}
}
}
}
}
}
