# Introduction
Dynamic C Development for Rabbit Semiconductor RCM4200, RCM5000, RCM6000 and similar. The project has been discontinued at the end of 2012. It waits for an reactivation in case of cooperation with any Dynamic C programmers. The structure can be changed but the programming concept should be kept.
# Content
## ALBAOS
Contains a simple monolitic kernel (with all the modules compiled).
* ALBAOS_ENVIRONMENT.H - defines the OS environment
* ALBAOS_RUN.LIB - defines which modules to compiled
* DEV - layer 0 device drivers
* DEV{1..3} - layer {1..3} device drivers (depends on a lower layer)
* SYS - system functionalities
* Useful - some examples
## OS_C
ALBAOS functionality tests.
## Packages
Extra C functions which deliver extra software capabilities.
* SCPI - Standard Commands for Programmable Instruments support
* SYSORD - standarized system orders
* XMLparser - Extensible Markup Language support
## Programs
Projects developed upon ALBAOS and Packages. Each project contans a different hardware architecture (PCB and connections). Not all the projects follow exactly this structure as ALBAOS was developed a bit later and as those projects were working, the development time was not invested to rewrite them. Each new project (so main function) should be developed in there.
* FIM - Fast Interlock Module: manages RF plant interlocks and safety
* GPSTS - GPS timestamp system for the machine timing
* HVS - High Voltate Splitter: to deliver HV power to ION pumps
* SimpleEM - first ALBA electrometer release
## Test
Extra test examples.
## Backup
Archives which contain one full code release.
