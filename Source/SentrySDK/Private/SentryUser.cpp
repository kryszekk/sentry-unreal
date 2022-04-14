// Copyright (c) 2022 Sentry. All Rights Reserved.

#include "SentryUser.h"
#include "Interface/SentryUserInterface.h"

#if PLATFORM_ANDROID
#include "Android/SentryUserAndroid.h"
#endif

#if PLATFORM_IOS
#include "IOS/SentryUserIOS.h"
#endif

#if PLATFORM_WINDOWS || PLATFORM_MAC
#include "Desktop/SentryUserDesktop.h"
#endif

USentryUser::USentryUser()
{
#if PLATFORM_ANDROID
	UserNativeImpl = MakeShareable(new SentryUserAndroid());
#endif
#if PLATFORM_IOS
	UserNativeImpl = MakeShareable(new SentryUserIOS());
#endif
#if PLATFORM_WINDOWS || PLATFORM_MAC
	UserNativeImpl = MakeShareable(new SentryUserDesktop());
#endif
}

void USentryUser::SetEmail(const FString& Email)
{
	if (!UserNativeImpl)
		return;

	UserNativeImpl->SetEmail(Email);
}

FString USentryUser::GetEmail() const
{
	if(!UserNativeImpl)
		return FString();

	return UserNativeImpl->GetEmail();
}

void USentryUser::SetId(const FString& Id)
{
	if (!UserNativeImpl)
		return;

	UserNativeImpl->SetId(Id);
}

FString USentryUser::GetId() const
{
	if(!UserNativeImpl)
		return FString();

	return UserNativeImpl->GetId();
}

void USentryUser::SetUsername(const FString& Username)
{
	if (!UserNativeImpl)
		return;

	UserNativeImpl->SetUsername(Username);
}

FString USentryUser::GetUsername() const
{
	if(!UserNativeImpl)
		return FString();

	return UserNativeImpl->GetUsername();
}

void USentryUser::SetIpAddress(const FString& IpAddress)
{
	if (!UserNativeImpl)
		return;

	UserNativeImpl->SetIpAddress(IpAddress);
}

FString USentryUser::GetIpAddress() const
{
	if(!UserNativeImpl)
		return FString();

	return UserNativeImpl->GetIpAddress();
}

void USentryUser::SetData(const TMap<FString, FString>& Data)
{
	if (!UserNativeImpl)
		return;

	UserNativeImpl->SetData(Data);
}

TMap<FString, FString> USentryUser::GetData() const
{
	if(!UserNativeImpl)
		return TMap<FString, FString>();

	return UserNativeImpl->GetData();
}

void USentryUser::InitWithNativeImpl(TSharedPtr<ISentryUser> userImpl)
{
	UserNativeImpl = userImpl;
}

TSharedPtr<ISentryUser> USentryUser::GetNativeImpl()
{
	return UserNativeImpl;
}
