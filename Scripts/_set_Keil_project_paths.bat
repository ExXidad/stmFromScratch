@echo off

SET PROJECT_FOLDER=.
SET KEIL_PROJECT_NAME_UVPROJX=stmFromScratch.uvprojx

SET PRODUCTION_FOLDER=Production
SET TMP_FOLDER=ci_tmp
SET BUILD_LOG=build.log

IF "%PROJECT_TARGET%"=="Target 1" (
	SET KEIL_PROJECT_OUTPUT_DIR=.\Objects\
	SET KEIL_PROJECT_LISTING_DIR=.\Listings\
	SET KEIL_PROJECT_OPTIM_LEVEL=1
)
SET PROJECT_TARGET_LIST[0]=Target 1
SET KEIL_PROJECT_OUTPUT_DIR_LIST[0]=.\Objects\
SET KEIL_PROJECT_LISTING_DIR_LIST[0]=.\Listings\
SET KEIL_PROJECT_OPTIM_LEVEL_LIST[0]=1

SET PROJECT_TARGET_LIST_LENGTH=0