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

namespace keyple {
namespace core {
namespace plugin {

/**
 * API associated to a
 * keyple::core::plugin::spi::reader::observable::state::removal::WaitForCardRemovalAutonomousSpi
 *
 * @since 2.0.0
 */
class WaitForCardRemovalAutonomousReaderApi {
public:
    /**
     *
     */
    virtual ~WaitForCardRemovalAutonomousReaderApi() = default;
    
    /**
     * Must be invoked when a card is removed.
     *
     * @since 2.0.0
     */
    virtual void onCardRemoved() = 0;
};

}
}
}
