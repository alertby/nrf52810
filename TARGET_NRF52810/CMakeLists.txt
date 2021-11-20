add_library(mbed-nrf52810 INTERFACE)


if(${MBED_TOOLCHAIN} STREQUAL "ARM")
    set(LINKER_FILE device/TOOLCHAIN_ARM_STD/nRF52810.sct)
    set(STARTUP_FILE device/TOOLCHAIN_ARM_STD/startup_nrf52810.S)
elseif(${MBED_TOOLCHAIN} STREQUAL "GCC_ARM")
    set(LINKER_FILE device/TOOLCHAIN_GCC_ARM/NRF52810.ld)
    set(STARTUP_FILE device/TOOLCHAIN_GCC_ARM/startup_NRF52810.S)
endif()

target_include_directories(mbed-nrf52810
    INTERFACE
        .
        config
        device

        ${STARTUP_FILE}
)

target_sources(mbed-nrf52810
    INTERFACE
        PeripheralPins.c

        device/cmsis_nvic.c
        device/system_nrf52.c
)

mbed_set_linker_script(mbed-nrf52810 ${CMAKE_CURRENT_SOURCE_DIR}/${LINKER_FILE})

target_link_libraries(mbed-nrf52810 INTERFACE mbed-nrf52 mbed-sdk-15-0)