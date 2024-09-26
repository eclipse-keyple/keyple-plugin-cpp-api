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
namespace removal {

/**
 * Reader that require an external active stimulation to detect card removal
 * without implementing a waiting mechanism.
 *
 * <p>A typical example of readers conforming to this mode of operation are
 * terminals embedding a slave RF communication module.
 *
 * @since 2.0.0
 * @deprecated Implement CardRemovalWaiterNonBlockingSpi instead (will be
 * removed in a future version of this API).
 */
class WaitForCardRemovalNonBlockingSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~WaitForCardRemovalNonBlockingSpi() = default;
};

} /* namespace removal */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
