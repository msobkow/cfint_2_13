--
--	@(#) dbcreate/cfint/db2luw/crtbl_licn.sql
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
CREATE TABLE cfinet213.licn (	\
	TenantId	BIGINT NOT NULL,	\
	Id	BIGINT NOT NULL,	\
	TopDomainId	BIGINT NOT NULL,	\
	safe_name	VARCHAR(64) NOT NULL,	\
	descr	VARCHAR(1024),	\
	EmbeddedText	CLOB(8000),	\
	FullTxt	CLOB(8000),	\
	Revision	int NOT NULL)	\
IN msidata1

CREATE UNIQUE INDEX CFINet213.lic_pk ON CFINet213.licn (	\
	TenantId,	\
	Id )

ALTER TABLE CFINet213.licn	\
	ADD CONSTRAINT pk_lic_pk PRIMARY KEY ( TenantId, Id )

commit
