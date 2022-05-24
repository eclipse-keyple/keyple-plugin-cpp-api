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

#include <memory>

/* Plugin */
#include "WaitForCardInsertionAutonomousReaderApi.h"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {
namespace observable {
namespace state {
namespace insertion {

using namespace keyple::core::plugin;

/**
 * Reader that have a fully integrated management of card communications for card insertion
 * detection.
 *
 * <p>A typical example of readers conforming to this mode of operation are Android-based NFC
 * readers.
 *
 * @since 2.0.0
 */
class WaitForCardInsertionAutonomousSpi {
public:
    /**
     * Connects the associated Keyple Core {@link WaitForCardInsertionAutonomousReaderApi} API.
     *
     * /!\ C++: cannot use a shared_ptr here as this is called from constructors
     *
     * @param waitForCardInsertionAutonomousReaderApi The API to connect.
     * @since 2.0.0
     */
    virtual void connect(
        WaitForCardInsertionAutonomousReaderApi* waitForCardInsertionAutonomousReaderApi) = 0;
};

}
}
}
}
}
}
}
}
