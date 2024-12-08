# *************************************************************************************************
# Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                         *
#                                                                                                 *
# This program and the accompanying materials are made available under the                        *
# terms of the MIT License which is available at https://opensource.org/licenses/MIT.             *
#                                                                                                 *
# SPDX-License-Identifier: MIT                                                                    *
# *************************************************************************************************/

SET(LIBRARY_NAME keypleplugin)

ADD_LIBRARY(
    ${LIBRARY_NAME}
    INTERFACE
)

ADD_LIBRARY(
    Keyple::Plugin
    ALIAS
    ${LIBRARY_NAME})

TARGET_INCLUDE_DIRECTORIES(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/keyple
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core/plugin
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core/plugin/spi
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core/plugin/spi/reader
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core/plugin/spi/reader/observable
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core/plugin/spi/reader/observable/state
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core/plugin/spi/reader/observable/state/insertion
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core/plugin/spi/reader/observable/state/processing
    ${CMAKE_CURRENT_LIST_DIR}/keyple/core/plugin/spi/reader/observable/state/removal
)
