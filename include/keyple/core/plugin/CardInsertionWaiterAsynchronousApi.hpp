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

/**
 * API associated to a
 * keyple::core::plugin::spi::reader::observable::state::insertion::CardInsertionWaiterAsynchronousSpi.
 *
 * @since 2.2.0
 */
class CardInsertionWaiterAsynchronousApi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardInsertionWaiterAsynchronousApi() = default;

    /**
     * Must be invoked when a card is inserted.
     *
     * @since 2.2.0
     */
    virtual void onCardInserted() = 0;
};

} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
