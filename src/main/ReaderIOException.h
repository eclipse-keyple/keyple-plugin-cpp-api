/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * See the NOTICE file(s) distributed with this work for additional information regarding         *
 * copyright ownership.                                                                           *
 *                                                                                                *
 * This program and the accompanying materials are made available under the terms of the Eclipse  *
 * Public License 2.0 which is available at http://www.eclipse.org/legal/epl-2.0                  *
 *                                                                                                *
 * SPDX-License-Identifier: EPL-2.0                                                               *
 **************************************************************************************************/

#pragma once

#include "Exception.h"

namespace keyple {
namespace core {
namespace plugin {

using namespace keyple::core::util::cpp::exception;

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
    ReaderIOException(const std::string& message) : Exception(message) {}

    /**
     * @param message the message to identify the exception context
     * @param cause the cause
     * @since 2.0.0
     */
    ReaderIOException(const std::string& message, const std::shared_ptr<Exception> cause)
    : Exception(message, cause) {}
};

}
}
}
