#pragma once

#include "RE/BSResourceLocation.h"  // BSResource::Location
#include "RE/BSSpinLock.h"  // BSSpinLock
#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	namespace BSResource
	{
		class GlobalLocations :
			public Location,						// 00
			public BSTSingletonSDM<GlobalLocations>	// 10
		{
		public:
			template <class T>
			struct List
			{
				List*	next;		// 00
				T		current;	// 08
				UInt64	unk10;		// ??
			};
			STATIC_ASSERT(sizeof(List<void*>) == 0x18);


			virtual ~GlobalLocations();																																	// 00

			// override (Location)
			virtual void	Unk_01(void) override;																														// 01
			virtual void	Unk_02(void) override;																														// 02
			virtual BOOL	QueryFileAttributes(const char* a_relPath, RE::BSResource::Stream*& a_stream, RE::BSResource::Location*& a_location, char a_arg4) override;	// 03
			virtual void	Unk_04(void) override;																														// 04
			virtual	BOOL	FindFiles(const char* a_relPath, LocationTraverser* a_traverser) override;																	// 05
			virtual void	Unk_06(void) override;																														// 06
			virtual void	Unk_07(void) override;																														// 07
			virtual void	Unk_08(void) override;																														// 08


			// members
			UInt8				pad11;	// 11
			UInt16				pad12;	// 12
			mutable BSSpinLock	lock;	// 14
			UInt32				unk1C;	// 1C
			List<Location*>*	unk20;	// 20
			List<void*>*		unk28;	// 28
			List<void*>*		unk30;	// 30
		};
		STATIC_ASSERT(sizeof(GlobalLocations) == 0x38);
	}
}