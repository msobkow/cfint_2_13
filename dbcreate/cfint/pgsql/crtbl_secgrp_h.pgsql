--
--	@(#) dbcreate/cfint/pgsql/crtbl_secgrp_h.pgsql
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
CREATE TABLE cfinet213.SecGrp_h (
	clusterid	bigint NOT NULL,
	secgroupid	integer NOT NULL,
	revision	INTEGER NOT NULL,
	auditclusterid	BIGINT NOT NULL,
		CONSTRAINT chk_secgrp_h_auditcluster
			FOREIGN KEY ( auditclusterid )
			REFERENCES cfinet213.clus( id )
			ON DELETE CASCADE,
	auditsessionid	VARCHAR(36) NOT NULL,
		CONSTRAINT chk_secgrp_h_auditsession
			FOREIGN KEY ( auditsessionid )
			REFERENCES cfinet213.SecSess( secsessionid )
			ON DELETE CASCADE,
	safe_name	varchar(64) NOT NULL,
	isvisible	boolean NOT NULL,
	auditaction	SMALLINT NOT NULL,
	auditstamp	TIMESTAMP NOT NULL )
	WITHOUT OIDS
	TABLESPACE cfinet213_data1;

CREATE UNIQUE INDEX secgrp_h_ididx ON cfinet213.secgrp_h (
	auditclusterid,
	auditstamp,
	clusterid,
	secgroupid,
	auditaction,
	revision )
	TABLESPACE cfinet213_idx1;

ALTER TABLE cfinet213.secgrp_h
	ADD CONSTRAINT pk_secgrp_h_ididx PRIMARY KEY ( auditclusterid, auditstamp, clusterid, secgroupid, auditaction, revision );
