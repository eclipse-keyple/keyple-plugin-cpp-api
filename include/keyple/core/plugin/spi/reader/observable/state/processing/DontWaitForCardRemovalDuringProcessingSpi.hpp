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
namespace processing {

/**
 * Reader <b>not</b> able to detect a card removal during processing, between two APDU commands.
 *
 * <p>A typical example of readers conforming to this mode of operation are are
 * terminals embedding a slave RF communication module.
 *
 * @since 2.0.0
 * @deprecated Useless SPI, don't implement it. Will be removed in a future
 * version of this API.
 */
class DontWaitForCardRemovalDuringProcessingSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~DontWaitForCardRemovalDuringProcessingSpi() = default;
};

} /* namespace processing */
} /* namespace state */
} /* namespace observable */
} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
