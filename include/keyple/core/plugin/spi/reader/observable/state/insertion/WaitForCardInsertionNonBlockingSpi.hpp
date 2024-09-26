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
namespace insertion {

/**
 * Reader that require an external active stimulation to detect card insertion
 * without implementing a waiting mechanism.
 *
 * <p>A typical example of readers conforming to this mode of operation are
 * terminals embedding a slave RF communication module.
 *
 * @since 2.0.0
 * @deprecated Implement CardInsertionWaiterNonBlockingSpi instead (will be
 * removed in a future version of this API).
 */
class WaitForCardInsertionNonBlockingSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~WaitForCardInsertionNonBlockingSpi() = default;
};

} /* namespace insertion */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
