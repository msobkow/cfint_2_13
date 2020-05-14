--
--	@(#) dbcreate/cfint/pgsql/crtbl_tdomdef.pgsql
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
CREATE TABLE cfinet213.tdomdef (
	createdat	TIMESTAMP NOT NULL,
	createdby	VARCHAR(36) NOT NULL,
	updatedat	TIMESTAMP NOT NULL,
	updatedby	VARCHAR(36) NOT NULL,
	tenantid	bigint NOT NULL,
	id	bigint NOT NULL,
	tldid	bigint NOT NULL,
	safe_name	varchar(64) NOT NULL,
	descr	varchar(1024) NULL,
	revision	INTEGER NOT NULL)
	WITHOUT OIDS
	TABLESPACE cfinet213_data1;

CREATE UNIQUE INDEX tdomdef_pk ON cfinet213.tdomdef (
	tenantid,
	id )
	TABLESPACE cfinet213_idx1;

ALTER TABLE cfinet213.tdomdef
	ADD CONSTRAINT pk_tdomdef_pk PRIMARY KEY ( tenantid, id );
