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

#include <memory>

#include "keyple/core/plugin/WaitForCardInsertionAutonomousReaderApi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {
namespace observable {
namespace state {
namespace insertion {

using keyple::core::plugin::WaitForCardInsertionAutonomousReaderApi;

/**
 * Reader that have a fully integrated management of card communications for
 * card insertion detection.
 *
 * <p>A typical example of readers conforming to this mode of operation are
 * Android-based NFC readers.
 *
 * @since 2.0.0
 * @deprecated Implement CardInsertionWaiterAsynchronousSpi instead (will be
 * removed in a future version of this API).
 */
class WaitForCardInsertionAutonomousSpi {
public:
    /**
     * Connects the associated Keyple Core {@link
     * WaitForCardInsertionAutonomousReaderApi} API.
     *
     * /!\ C++: cannot use a shared_ptr here as this is called from constructors
     *
     * @param waitForCardInsertionAutonomousReaderApi The API to connect.
     * @since 2.0.0
     * @deprecated
     */
    virtual void connect(WaitForCardInsertionAutonomousReaderApi*
                             waitForCardInsertionAutonomousReaderApi)
        = 0;
};

} /* namespace insertion */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
