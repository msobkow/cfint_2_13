--
--	@(#) dbcreate/cfint/db2luw/crtbl_secgrpfrm_h.sql
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
CREATE TABLE cfinet213.secgrpfrm_h (	\
	clusid	BIGINT NOT NULL,	\
	secgrpfrmid	BIGINT NOT NULL,	\
	Revision	int NOT NULL,	\
	auditclusterid	BIGINT NOT NULL,	\
		CONSTRAINT chk_secgrpfrm_h_auditcluster	\
			FOREIGN KEY ( auditclusterid )	\
			REFERENCES cfinet213.clus( id )	\
			ON DELETE CASCADE,	\
	auditsessionid	VARCHAR(36) NOT NULL,	\
		CONSTRAINT chk_secgrpfrm_h_auditsession	\
			FOREIGN KEY ( auditsessionid )	\
			REFERENCES cfinet213.SecSess( secsessionid )	\
			ON DELETE CASCADE,	\
	SecGrpId	INT NOT NULL,	\
	SecAppId	INT NOT NULL,	\
	SecFrmId	INT NOT NULL,	\
	auditaction	SMALLINT NOT NULL,	\
	auditstamp	TIMESTAMP NOT NULL )	\
IN msidata1

CREATE UNIQUE INDEX cfinet213.secgrpfrm_h_ididx ON cfinet213.secgrpfrm_h (	\
	auditclusterid,	\
	auditstamp,	\
	ClusId,	\
	SecGrpFrmId,	\
	auditaction,	\
	revision )

ALTER TABLE cfinet213.secgrpfrm_h	\
	ADD CONSTRAINT pk_secgroupform_pidx_h PRIMARY KEY (	\
	auditclusterid,	\
	auditstamp, ClusId, SecGrpFrmId,	\
	auditaction,	\
	revision )
