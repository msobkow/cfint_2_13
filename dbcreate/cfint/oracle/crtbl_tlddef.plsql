--
--	@(#) dbcreate/cfint/oracle/crtbl_tlddef.plsql
--
--	com.github.msobkow.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	This file is part of MSS Code Factory.
--	
--	Licensed under the Apache License, Version 2.0 (the "License");
--	you may not use this file except in compliance with the License.
--	You may obtain a copy of the License at
--	
--	    http://www.apache.org/licenses/LICENSE-2.0
--	
--	Unless required by applicable law or agreed to in writing, software
--	distributed under the License is distributed on an "AS IS" BASIS,
--	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
--	See the License for the specific language governing permissions and
--	limitations under the License.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--
--	Manufactured by MSS Code Factory 2.12
--
CREATE TABLE cfinet213.tlddef (
	createdat	TIMESTAMP NOT NULL,
	createdby	VARCHAR(36) NOT NULL,
	updatedat	TIMESTAMP NOT NULL,
	updatedby	VARCHAR(36) NOT NULL,
	tenantid	numeric(22,0) NOT NULL,
	id	numeric(22,0) NOT NULL,
	safe_name	varchar2(64) NOT NULL,
	descr	varchar2(1024) NULL,
	revision	INTEGER NOT NULL)
TABLESPACE cfinet213_data1;

CREATE UNIQUE INDEX tlddef_pk ON cfinet213.tlddef (
	tenantid,
	id ) TABLESPACE cfinet213_idx1;

ALTER TABLE cfinet213.tlddef
	ADD CONSTRAINT pk_tlddef_pk PRIMARY KEY ( tenantid, id );

