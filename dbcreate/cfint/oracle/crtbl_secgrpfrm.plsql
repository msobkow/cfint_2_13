--
--	@(#) dbcreate/cfint/oracle/crtbl_secgrpfrm.plsql
--
--	org.msscf.msscf.CFInt
--
--	Copyright (c) 2020 Mark Stephen Sobkow
--	
--	MSS Code Factory CFSec 2.13 Security Essentials
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
CREATE TABLE cfinet213.SecGrpFrm (
	createdat	TIMESTAMP NOT NULL,
	createdby	VARCHAR(36) NOT NULL,
	updatedat	TIMESTAMP NOT NULL,
	updatedby	VARCHAR(36) NOT NULL,
	clusid	numeric(22,0) NOT NULL,
	secgrpfrmid	numeric(22,0) NOT NULL,
	secgrpid	integer NOT NULL,
	secappid	integer NOT NULL,
	secfrmid	integer NOT NULL,
	revision	INTEGER NOT NULL)
TABLESPACE cfinet213_data1;

CREATE UNIQUE INDEX SecGroupForm_pidx ON cfinet213.SecGrpFrm (
	clusid,
	secgrpfrmid ) TABLESPACE cfinet213_idx1;

ALTER TABLE cfinet213.SecGrpFrm
	ADD CONSTRAINT pk_secgroupform_pidx PRIMARY KEY ( clusid, secgrpfrmid );

