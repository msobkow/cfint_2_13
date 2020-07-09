--
--	@(#) dbcreate/cfint/db2luw/crrel_iso_cntrylng.sql
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

ALTER TABLE CFINet213.iso_cntrylng ADD CONSTRAINT isocntrylang_cntry	\
	FOREIGN KEY (	\
		ISOCtryId	\
	) REFERENCES CFINet213.iso_cntry (	\
		ISOCtryId	\
	) ON DELETE RESTRICT

ALTER TABLE CFINet213.iso_cntrylng ADD CONSTRAINT isocntrylang_lang	\
	FOREIGN KEY (	\
		ISOLangId	\
	) REFERENCES CFINet213.iso_lang (	\
		ISOLangId	\
	) ON DELETE RESTRICT

commit
