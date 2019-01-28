#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

#include "RE/FormTypes.h"  // TESForm


namespace RE
{
	class BSString;


	class TESDescription : public BaseFormComponent
	{
	public:
		virtual ~TESDescription();											// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03

		/*
		 * @param a_fieldType 'DESC', etc
		 */
		void			Get(BSString& a_out, TESForm* a_parent, UInt32 a_fieldType);


		// members
		UInt32	unk08;	// 08
		UInt32	unk0C;	// 0C - init'd to FFFFFFFF
	};
	STATIC_ASSERT(sizeof(TESDescription) == 0x10);
}