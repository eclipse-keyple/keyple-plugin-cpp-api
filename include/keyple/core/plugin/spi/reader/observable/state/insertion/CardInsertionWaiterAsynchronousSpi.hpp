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

#include "keyple/core/plugin/CardInsertionWaiterAsynchronousApi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {
namespace observable {
namespace state {
namespace insertion {

/**
 * This SPI is specifically designed for plugins that handle card insertion
 * asynchronously.
 *
 * <p>A typical example of readers conforming to this mode of operation are
 * Android-based NFC readers.
 *
 * @since 2.2.0
 */
class CardInsertionWaiterAsynchronousSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardInsertionWaiterAsynchronousSpi() = default;

    /**
     * Sets the asynchronous callback that will be called when a card is
     * inserted.
     *
     * @param callback The asynchronous callback to be called.
     * @since 2.2.0
     */
    virtual void setCallback(CardInsertionWaiterAsynchronousApi* callback) = 0;
};

} /* namespace insertion */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
