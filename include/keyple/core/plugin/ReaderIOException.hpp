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
#include <string>

#include "keyple/core/util/cpp/exception/Exception.hpp"

namespace keyple {
namespace core {
namespace plugin {

using keyple::core::util::cpp::exception::Exception;

/**
 * Indicates that an error occurred while communicating with a reader.
 *
 * @since 2.0.0
 */
class ReaderIOException : public Exception {
public:
    /**
     * @param message the message to identify the exception context
     * @since 2.0.0
     */
    explicit ReaderIOException(const std::string& message)
    : Exception(message) {
    }

    /**
     * @param message the message to identify the exception context
     * @param cause the cause
     * @since 2.0.0
     */
    ReaderIOException(
        const std::string& message, const std::shared_ptr<Exception> cause)
    : Exception(message, cause) {
    }
};

} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
