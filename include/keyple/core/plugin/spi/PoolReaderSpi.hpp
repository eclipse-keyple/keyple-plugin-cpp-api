/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <memory>

#include "keyple/core/plugin/spi/reader/ReaderSpi.hpp"
#include "keyple/core/util/cpp/Any.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

using keyple::core::plugin::spi::reader::ReaderSpi;
using keyple::core::util::cpp::any;

/**
 * Reader extension for pool readers.
 *
 * @since 2.1.0
 */
class PoolReaderSpi : public ReaderSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~PoolReaderSpi() = default;

    /**
     * Returns the selected smart card when it has been provided by the reader allocation process.
     *
     * @return Null if no smart card is selected by default, the selected smart card otherwise.
     * @since 2.1.0
     */
    virtual std::shared_ptr<any> getSelectedSmartCard();
};

} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
