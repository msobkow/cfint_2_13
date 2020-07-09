--
--	@(#) dbcreate/cfint/pgsql/crtbl_tlddef_h.pgsql
--
--	org.msscf.msscf.CFInt
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
CREATE TABLE cfinet213.tlddef_h (
	tenantid	bigint NOT NULL,
	id	bigint NOT NULL,
	revision	INTEGER NOT NULL,
	auditclusterid	BIGINT NOT NULL,
		CONSTRAINT chk_tlddef_h_auditcluster
			FOREIGN KEY ( auditclusterid )
			REFERENCES cfinet213.clus( id )
			ON DELETE CASCADE,
	auditsessionid	VARCHAR(36) NOT NULL,
		CONSTRAINT chk_tlddef_h_auditsession
			FOREIGN KEY ( auditsessionid )
			REFERENCES cfinet213.SecSess( secsessionid )
			ON DELETE CASCADE,
	safe_name	varchar(64) NOT NULL,
	descr	varchar(1024) NULL,
	auditaction	SMALLINT NOT NULL,
	auditstamp	TIMESTAMP NOT NULL )
	WITHOUT OIDS
	TABLESPACE cfinet213_data1;

CREATE UNIQUE INDEX tlddef_h_ididx ON cfinet213.tlddef_h (
	auditclusterid,
	auditstamp,
	tenantid,
	id,
	auditaction,
	revision )
	TABLESPACE cfinet213_idx1;

ALTER TABLE cfinet213.tlddef_h
	ADD CONSTRAINT pk_tlddef_h_ididx PRIMARY KEY ( auditclusterid, auditstamp, tenantid, id, auditaction, revision );
