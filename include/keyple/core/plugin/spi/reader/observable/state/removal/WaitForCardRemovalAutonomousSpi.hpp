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

/* Plugin */
#include "keyple/core/plugin/WaitForCardRemovalAutonomousReaderApi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {
namespace observable {
namespace state {
namespace removal {

using keyple::core::plugin::WaitForCardRemovalAutonomousReaderApi;

/**
 * Reader that have a fully integrated management of card communications for
 * card removal detection.
 *
 * <p>A typical example of readers conforming to this mode of operation are
 * Android-based NFC readers.
 *
 * @since 2.0.0
 * @deprecated Implement CardRemovalWaiterAsynchronousSpi instead (will be
 * removed in a future version of this API).
 */
class WaitForCardRemovalAutonomousSpi {
public:
    /**
     * Connects the associated Keyple Core {@link
     * WaitForCardRemovalAutonomousReaderApi} API.
     *
     * /!\ C++: cannot use a shared_ptr for reader as this is called from constructors
     *
     * @param waitForCardRemovalAutonomousReaderApi The API to connect.
     * @since 2.0.0
     * @deprecated
     */
    virtual void connect(WaitForCardRemovalAutonomousReaderApi*
                             waitForCardRemovalAutonomousReaderApi)
        = 0;
};

} /* namespace removal */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
