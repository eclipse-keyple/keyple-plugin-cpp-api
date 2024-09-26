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

#include <string>

#include "keyple/core/util/cpp/exception/Exception.hpp"

namespace keyple {
namespace core {
namespace plugin {

using keyple::core::util::cpp::exception::Exception;

/**
 * Indicates that a task (for example, waiting for a card to be inserted) has
 * been cancelled and is no longer active.
 *
 * @since 2.0.0
 */
class TaskCanceledException : public Exception {
public:
    /**
     * @param message the message to identify the exception context
     * @since 2.0.0
     */
    explicit TaskCanceledException(const std::string& message)
    : Exception(message) {
    }
};

} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
