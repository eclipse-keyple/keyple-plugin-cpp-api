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

#include "keyple/core/plugin/CardRemovalWaiterAsynchronousApi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {
namespace observable {
namespace state {
namespace removal {

using keyple::core::plugin::CardRemovalWaiterAsynchronousApi;

/**
 * This SPI is specifically designed for plugins that handle card removal
 * asynchronously.
 *
 * @since 2.2.0
 */
class CardRemovalWaiterAsynchronousSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardRemovalWaiterAsynchronousSpi() = default;

    /**
     * Sets the asynchronous callback that will be called when the card removal
     * is complete.
     *
     * @param callback The asynchronous callback to be called.
     * @since 2.2.0
     */
    virtual void setCallback(CardRemovalWaiterAsynchronousApi* callback) = 0;
};

} /* namespace removal */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
