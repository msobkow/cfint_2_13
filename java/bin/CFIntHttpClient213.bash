#!/bin/bash
cd $MSSCFHOME/cfint_2_13/java/bin
if [ "$LOG4J2_CONF" != "" ]; then
	export JAVA_LOG4J="-Dlog4j.configurationFile=$LOG4J2_CONF"
else
	export JAVA_LOG4J=""
fi
export PATH=".:$PATH"
$JAVA $JAVA_LOG4J -Xms1023M --module-path "$PATH_TO_FX${JSEP}./lib${JSEP}com.github.msobkow.cfintcust.CFIntCustHttp.jar${JSEP}com.github.msobkow.cfintcust.CFIntCust.jar${JSEP}com.github.msobkow.cfint.CFIntJavaFX.jar${JSEP}com.github.msobkow.cfint.CFIntXMsgClnt.jar${JSEP}com.github.msobkow.cfint.CFIntXMsgRspn.jar${JSEP}com.github.msobkow.cfint.CFIntXMsg.jar${JSEP}com.github.msobkow.cfint.CFIntSaxLoader.jar${JSEP}com.github.msobkow.cfint.jar${JSEP}com.github.msobkow.cfseccust.CFSecCust.jar${JSEP}com.github.msobkow.cfsec.CFSecJavaFX.jar${JSEP}com.github.msobkow.cfsec.CFSecSaxLoader.jar${JSEP}com.github.msobkow.cfsec.jar${JSEP}com.github.msobkow.cflib.CFLib.JavaFX.jar${JSEP}com.github.msobkow.cflib.CFLib.jar" -m com.github.msobkow.cfintcust.CFIntCustHttp/com.github.msobkow.cfintcust.CFIntCustHttp.CFIntCustHttp $@

