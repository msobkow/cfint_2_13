--
--	@(#) dbcreate/cfint/pgsql/crtbl_isotz.pgsql
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
CREATE TABLE cfinet213.ISOTz (
	createdat	TIMESTAMP NOT NULL,
	createdby	VARCHAR(36) NOT NULL,
	updatedat	TIMESTAMP NOT NULL,
	updatedby	VARCHAR(36) NOT NULL,
	isotzoneid	smallint NOT NULL,
	iso8601	varchar(6) NOT NULL,
	tzname	varchar(64) NOT NULL,
	tzhouroffset	smallint NOT NULL,
	tzminoffset	smallint NOT NULL,
	description	varchar(128) NOT NULL,
	visible	boolean NOT NULL,
	revision	INTEGER NOT NULL)
	WITHOUT OIDS
	TABLESPACE cfinet213_data1;

CREATE UNIQUE INDEX ITz_pidx ON cfinet213.ISOTz (
	isotzoneid )
	TABLESPACE cfinet213_idx1;

ALTER TABLE cfinet213.ISOTz
	ADD CONSTRAINT pk_itz_pidx PRIMARY KEY ( isotzoneid );