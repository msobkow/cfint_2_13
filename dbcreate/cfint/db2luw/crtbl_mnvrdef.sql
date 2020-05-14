--
--	@(#) dbcreate/cfint/db2luw/crtbl_mnvrdef.sql
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
CREATE TABLE cfinet213.mnvrdef (	\
	createdat	TIMESTAMP NOT NULL,	\
	createdby	VARCHAR(36) NOT NULL,	\
	updatedat	TIMESTAMP NOT NULL,	\
	updatedby	VARCHAR(36) NOT NULL,	\
	TenantId	BIGINT NOT NULL,	\
	Id	BIGINT NOT NULL,	\
	MajorVersionId	BIGINT NOT NULL,	\
	safe_name	VARCHAR(64) NOT NULL,	\
	descr	VARCHAR(1024),	\
	Revision	int NOT NULL)	\
IN msidata1

CREATE UNIQUE INDEX CFINet213.mnvrdef_pk ON CFINet213.mnvrdef (	\
	TenantId,	\
	Id )

ALTER TABLE CFINet213.mnvrdef	\
	ADD CONSTRAINT pk_mnvrdef_pk PRIMARY KEY ( TenantId, Id )

commit
