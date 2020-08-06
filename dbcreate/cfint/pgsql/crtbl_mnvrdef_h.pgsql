--
--	@(#) dbcreate/cfint/pgsql/crtbl_mnvrdef_h.pgsql
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
CREATE TABLE cfinet213.mnvrdef_h (
	tenantid	bigint NOT NULL,
	id	bigint NOT NULL,
	revision	INTEGER NOT NULL,
	auditclusterid	BIGINT NOT NULL,
		CONSTRAINT chk_mnvrdef_h_auditcluster
			FOREIGN KEY ( auditclusterid )
			REFERENCES cfinet213.clus( id )
			ON DELETE CASCADE,
	auditsessionid	VARCHAR(36) NOT NULL,
		CONSTRAINT chk_mnvrdef_h_auditsession
			FOREIGN KEY ( auditsessionid )
			REFERENCES cfinet213.SecSess( secsessionid )
			ON DELETE CASCADE,
	majorversionid	bigint NOT NULL,
	safe_name	varchar(64) NOT NULL,
	descr	varchar(1024) NULL,
	auditaction	SMALLINT NOT NULL,
	auditstamp	TIMESTAMP NOT NULL )
	WITHOUT OIDS
	TABLESPACE cfinet213_data1;

CREATE UNIQUE INDEX mnvrdef_h_ididx ON cfinet213.mnvrdef_h (
	auditclusterid,
	auditstamp,
	tenantid,
	id,
	auditaction,
	revision )
	TABLESPACE cfinet213_idx1;

ALTER TABLE cfinet213.mnvrdef_h
	ADD CONSTRAINT pk_mnvrdef_h_ididx PRIMARY KEY ( auditclusterid, auditstamp, tenantid, id, auditaction, revision );
