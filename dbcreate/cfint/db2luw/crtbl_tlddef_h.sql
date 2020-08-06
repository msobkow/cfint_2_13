--
--	@(#) dbcreate/cfint/db2luw/crtbl_tlddef_h.sql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFInt 2.13 Internet Essentials
--	
--	Copyright 2020 Mark Stephen Sobkow
--	
--		This file is part of MSS Code Factory.
--	
--		MSS Code Factory is available under dual commercial license from Mark Stephen
--		Sobkow, or under the terms of the GNU General Public License, Version 3
--		or later.
--	
--	    MSS Code Factory is free software: you can redistribute it and/or modify
--	    it under the terms of the GNU General Public License as published by
--	    the Free Software Foundation, either version 3 of the License, or
--	    (at your option) any later version.
--	
--	    MSS Code Factory is distributed in the hope that it will be useful,
--	    but WITHOUT ANY WARRANTY; without even the implied warranty of
--	    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--	    GNU General Public License for more details.
--	
--	    You should have received a copy of the GNU General Public License
--	    along with MSS Code Factory.  If not, see <https://www.gnu.org/licenses/>.
--	
--	Donations to support MSS Code Factory can be made at
--	https://www.paypal.com/paypalme2/MarkSobkow
--	
--	Please contact Mark Stephen Sobkow at msobkow@sasktel.net for commercial licensing.
--
--	Manufactured by MSS Code Factory 2.12
--
CREATE TABLE cfinet213.tlddef_h (	\
	tenantid	BIGINT NOT NULL,	\
	id	BIGINT NOT NULL,	\
	Revision	int NOT NULL,	\
	auditclusterid	BIGINT NOT NULL,	\
		CONSTRAINT chk_tlddef_h_auditcluster	\
			FOREIGN KEY ( auditclusterid )	\
			REFERENCES cfinet213.clus( id )	\
			ON DELETE CASCADE,	\
	auditsessionid	VARCHAR(36) NOT NULL,	\
		CONSTRAINT chk_tlddef_h_auditsession	\
			FOREIGN KEY ( auditsessionid )	\
			REFERENCES cfinet213.SecSess( secsessionid )	\
			ON DELETE CASCADE,	\
	safe_name	VARCHAR(64) NOT NULL,	\
	descr	VARCHAR(1024),	\
	auditaction	SMALLINT NOT NULL,	\
	auditstamp	TIMESTAMP NOT NULL )	\
IN msidata1

CREATE UNIQUE INDEX cfinet213.tlddef_h_ididx ON cfinet213.tlddef_h (	\
	auditclusterid,	\
	auditstamp,	\
	TenantId,	\
	Id,	\
	auditaction,	\
	revision )

ALTER TABLE cfinet213.tlddef_h	\
	ADD CONSTRAINT pk_tlddef_pk_h PRIMARY KEY (	\
	auditclusterid,	\
	auditstamp, TenantId, Id,	\
	auditaction,	\
	revision )

