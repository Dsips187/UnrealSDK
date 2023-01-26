﻿#include "MockBeamContentObject.h"

#include "Engine/Engine.h"
#include "Misc/AutomationTest.h"


void FBeamContentObjectSpec::Define()
{
	FString TestId = TEXT("mockcontentobject.content1");
	FString TestVersion = TEXT("1");
	FString TestBeamCid = TEXT("111111111");
	FString TestValueA = TEXT("1");
	FString TestValueB = TEXT("2");
	int32 TestValueAInt = 1;
	int32 TestValueBInt = 2;

	FString FullObject = TEXT(R"({
  "id": "₢Id₢",
  "version": "₢Version₢",
  "properties": {
    "Value": {
      "data": ₢ValueA₢
    },
    "BeamCid": {
      "data": "₢BeamCid₢"
    },
	"ArrayOfU8": {
      "data": [
        ₢ValueA₢,
        ₢ValueB₢
      ]
    },
	"ArrayOfString": {
      "data": [
        "₢ValueA₢",
        "₢ValueB₢"
      ]
    },
    "ArrayOfBeamCid": {
      "data": [
        "₢BeamCid₢"
      ]
    },
	"MapOfU8": {
      "data": {
        "a": ₢ValueA₢
      }
    },
	"MapOfString": {
      "data": {
        "a": "₢ValueA₢"
      }
    },
    "MapOfBeamCid": {
      "data": {
        "a": "₢BeamCid₢"
      }
    },    
    "BeamArrayOfString": {
      "data": ["₢ValueA₢"]
    },
    "BeamMapOfString": {
      "data": {
		"a" : "₢ValueA₢"
		}
    },
    "ArrayOfArrayOfString": {
      "data": [
        [
          "₢ValueA₢",
          "₢ValueB₢"
        ]
      ]
    },
    "ArrayOfMapOfString": {
      "data": [
        {
          "a": "₢ValueA₢"
        },
        {
          "a": "₢ValueB₢"
        }
      ]
    },
    "MapOfArrayOfString": {
      "data": {
        "a": [
          "₢ValueA₢",
          "₢ValueB₢"
        ]
      }
    },
    "MapOfMapOfString": {
      "data": {
        "a": {
          "a": "₢ValueA₢"
        }
      }
    },
    "BeamOptionalBool": {
      "data": false
    },
    "BeamOptionalArrayOfInt32": {
      "data": [
        ₢ValueA₢,
        ₢ValueB₢
      ]
    },
    "BeamOptionalMapOfInt64": {
      "data": {
        "a": ₢ValueA₢
      }
    },
    "BeamOptionalBeamCid": {
      "data": "₢BeamCid₢"
    },
    "BeamOptionalArrayOfBeamPid": {
      "data": [
        "₢BeamCid₢"
      ]
    }
  }
})");

	FString WithoutOptionals = TEXT(R"({
  "id": "₢Id₢",
  "version": "₢Version₢",
  "properties": {
    "Value": {
      "data": ₢ValueA₢
    },
    "BeamCid": {
      "data": "₢BeamCid₢"
    },
	"ArrayOfU8": {
      "data": [
        ₢ValueA₢,
        ₢ValueB₢
      ]
    },
	"ArrayOfString": {
      "data": [
        "₢ValueA₢",
        "₢ValueB₢"
      ]
    },
    "ArrayOfBeamCid": {
      "data": [
        "₢BeamCid₢"
      ]
    },
	"MapOfU8": {
      "data": {
        "a": ₢ValueA₢
      }
    },
	"MapOfString": {
      "data": {
        "a": "₢ValueA₢"
      }
    },
    "MapOfBeamCid": {
      "data": {
        "a": "₢BeamCid₢"
      }
    },    
    "BeamArrayOfString": {
      "data": ["₢ValueA₢"]
    },
    "BeamMapOfString": {
      "data": {
		"a" : "₢ValueA₢"
		}
    },
    "ArrayOfArrayOfString": {
      "data": [
        [
          "₢ValueA₢",
          "₢ValueB₢"
        ]
      ]
    },
    "ArrayOfMapOfString": {
      "data": [
        {
          "a": "₢ValueA₢"
        },
        {
          "a": "₢ValueB₢"
        }
      ]
    },
    "MapOfArrayOfString": {
      "data": {
        "a": [
          "₢ValueA₢",
          "₢ValueB₢"
        ]
      }
    },
    "MapOfMapOfString": {
      "data": {
        "a": {
          "a": "₢ValueA₢"
        }
      }
    }
  }
})");

	FullObject = FullObject.Replace(TEXT("₢Id₢"), *TestId);
	FullObject = FullObject.Replace(TEXT("₢Version₢"), *TestVersion);
	FullObject = FullObject.Replace(TEXT("₢BeamCid₢"), *TestBeamCid);
	FullObject = FullObject.Replace(TEXT("₢ValueA₢"), *TestValueA);
	FullObject = FullObject.Replace(TEXT("₢ValueB₢"), *TestValueB);


	WithoutOptionals = WithoutOptionals.Replace(TEXT("₢Id₢"), *TestId);
	WithoutOptionals = WithoutOptionals.Replace(TEXT("₢Version₢"), *TestVersion);
	WithoutOptionals = WithoutOptionals.Replace(TEXT("₢BeamCid₢"), *TestBeamCid);
	WithoutOptionals = WithoutOptionals.Replace(TEXT("₢ValueA₢"), *TestValueA);
	WithoutOptionals = WithoutOptionals.Replace(TEXT("₢ValueB₢"), *TestValueB);

	Describe("Content Serialization", [=]()
	{
		BeforeEach([=, this]()
		{
			ContentObject = NewObject<UMockBeamContentObject>();
			ContentObject->Id = TestId;
			ContentObject->Version = TestVersion;
			ContentObject->Value = TestValueAInt;
			ContentObject->BeamCid = TestBeamCid;

			ContentObject->ArrayOfU8 = TArray{static_cast<uint8>(TestValueAInt), static_cast<uint8>(TestValueBInt)};
			ContentObject->ArrayOfString = TArray{TestValueA, TestValueB};
			ContentObject->ArrayOfBeamCid = TArray{FBeamCid{TestBeamCid}};

			ContentObject->BeamArrayOfString = FArrayOfString(TArray{TestValueA});
			ContentObject->ArrayOfArrayOfString = TArray{FArrayOfString(TArray{TestValueA, TestValueB})};
			ContentObject->ArrayOfMapOfString = TArray{
				FMapOfString(TMap<FString, FString>{{TEXT("a"), TestValueA}}),
				FMapOfString(TMap<FString, FString>{{TEXT("a"), TestValueB}})
			};

			ContentObject->MapOfU8 = TMap<FString, uint8>{{TEXT("a"), static_cast<uint8>(TestValueAInt)}};
			ContentObject->MapOfString = TMap<FString, FString>{{TEXT("a"), TestValueA}};
			ContentObject->MapOfBeamCid = TMap<FString, FBeamCid>{{TEXT("a"), FBeamCid{TestBeamCid}}};

			ContentObject->BeamMapOfString = FMapOfString(TMap<FString, FString>{{TEXT("a"), TestValueA}});
			ContentObject->MapOfArrayOfString = TMap<FString, FArrayOfString>{{TEXT("a"), FArrayOfString(TArray{TestValueA, TestValueB})}};
			ContentObject->MapOfMapOfString = TMap<FString, FMapOfString>{{TEXT("a"), FMapOfString(TMap<FString, FString>{{TEXT("a"), TestValueA}})}};
		});

		AfterEach([=, this]()
		{
			ContentObject = nullptr;
		});

		It("should serialize ids and version", [=, this]()
		{
			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			TestEqual("Id serialized correctly", NewObj->Id, TestId);
			TestEqual("Version serialized correctly", NewObj->Version, TestVersion);
			NewObj = nullptr;
		});

		It("should serialize primitives properly", [=, this]()
		{
			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			TestEqual("value serialized correctly", NewObj->Value, TestValueAInt);
			NewObj = nullptr;
		});

		It("should serialize semantic types properly", [=, this]()
		{
			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			TestEqual("BeamCid serialized correctly", NewObj->BeamCid.AsString, TestBeamCid);
			NewObj = nullptr;
		});

		It("should serialize TArray<> properly", [=, this]()
		{
			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			const auto ExpectedArrayOfU8 = TArray{static_cast<uint8>(TestValueAInt), static_cast<uint8>(TestValueBInt)};
			const auto ExpectedArrayOfString = TArray{TestValueA, TestValueB};

			TestEqual("U8 Array serialized correctly", NewObj->ArrayOfU8, ExpectedArrayOfU8);
			TestEqual("String Array serialized correctly", NewObj->ArrayOfString, ExpectedArrayOfString);
			TestEqual("String Array serialized correctly", NewObj->ArrayOfBeamCid[0], FBeamCid{TestBeamCid});
		});

		It("should serialize TMap<FString,> properly", [=, this]()
		{
			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			TestEqual("U8 Array serialized correctly", NewObj->MapOfU8.FindRef(TEXT("a")), TestValueAInt);
			TestEqual("String Array serialized correctly", NewObj->MapOfString.FindRef(TEXT("a")), TestValueA);
			TestEqual("String Array serialized correctly", NewObj->MapOfBeamCid.FindRef(TEXT("a")), FBeamCid{TestBeamCid});
		});

		It("should serialize BeamArrays properly", [=, this]()
		{
			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			TestEqual("FArrayOfString deserialized correctly", NewObj->BeamArrayOfString.Values[0], TestValueA);
			TestEqual("TArray<FArrayOfString> deserialized correctly", NewObj->ArrayOfArrayOfString[0].Values[0], TestValueA);
			TestEqual("TArray<FArrayOfString> deserialized correctly", NewObj->ArrayOfArrayOfString[0].Values[1], TestValueB);
			TestEqual("TArray<FMapOfString> deserialized correctly", NewObj->ArrayOfMapOfString[0].Values.FindRef(TEXT("a")), TestValueA);
			TestEqual("TArray<FMapOfString> deserialized correctly", NewObj->ArrayOfMapOfString[1].Values.FindRef(TEXT("a")), TestValueB);
		});

		It("should serialize BeamMaps properly", [=, this]()
		{
			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			TestEqual("FMapOfString deserialized correctly", NewObj->BeamMapOfString.Values.FindRef(TEXT("a")), TestValueA);
			TestEqual("TMap<FString, FArrayOfString> deserialized correctly", NewObj->MapOfArrayOfString.FindRef("a").Values[0], TestValueA);
			TestEqual("TMap<FString, FArrayOfString> deserialized correctly", NewObj->MapOfArrayOfString.FindRef("a").Values[1], TestValueB);
			TestEqual("TMap<FString, FMapOfString> deserialized correctly", NewObj->MapOfMapOfString.FindRef("a").Values.FindRef("a"), TestValueA);
		});

		It("should serialize BeamOptionals properly", [=, this]()
		{
			ContentObject->BeamOptionalBool = FOptionalBool(false);
			ContentObject->BeamOptionalBeamCid = FOptionalBeamCid(TestBeamCid);
			ContentObject->BeamOptionalArrayOfInt32 = FOptionalArrayOfInt32(TArray{TestValueAInt, TestValueBInt});
			ContentObject->BeamOptionalMapOfInt64 = FOptionalMapOfInt64(TMap<FString, int64>{{TEXT("a"), static_cast<int64>(TestValueAInt)}});
			ContentObject->BeamOptionalArrayOfBeamPid = FOptionalArrayOfBeamPid(TArray{FBeamPid(TestBeamCid)});

			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			TestEqual("Optional of Primitive deserialized correctly", NewObj->BeamOptionalBool.Val, false);
			TestEqual("Optional of semantic type deserialized correctly", NewObj->BeamOptionalBeamCid.Val.AsString, TestBeamCid);

			TestEqual("Optional of TArray<int> deserialized correctly", NewObj->BeamOptionalArrayOfInt32.Val[0], TestValueAInt);
			TestEqual("Optional of TArray<int> deserialized correctly", NewObj->BeamOptionalArrayOfInt32.Val[1], TestValueBInt);

			TestEqual("Optional of TMap<FString, int> deserialized correctly", NewObj->BeamOptionalMapOfInt64.Val.FindRef("a"), TestValueAInt);

			TestEqual("Optional of TArray of Semantic Type deserialized correctly", NewObj->BeamOptionalArrayOfBeamPid.Val[0].AsString, TestBeamCid);
		});

		It("should deserialize BeamOptionals as unset when they are not in the JSON", [=, this]()
		{
			FString Json = FString{};
			ContentObject->ToJson(Json);

			auto NewObj = NewObject<UMockBeamContentObject>();
			NewObj->FromJson(Json);

			TestEqual("Optional of Primitive deserialized correctly", NewObj->BeamOptionalBool.IsSet, false);
			TestEqual("Optional of Primitive deserialized correctly", NewObj->BeamOptionalBeamCid.IsSet, false);
			TestEqual("Optional of Primitive deserialized correctly", NewObj->BeamOptionalArrayOfInt32.IsSet, false);
			TestEqual("Optional of Primitive deserialized correctly", NewObj->BeamOptionalMapOfInt64.IsSet, false);
			TestEqual("Optional of Primitive deserialized correctly", NewObj->BeamOptionalArrayOfBeamPid.IsSet, false);
		});
	});

	Describe("Content Deserialization", [=]()
	{
		BeforeEach([=, this]()
		{
			ContentObject = NewObject<UMockBeamContentObject>();
		});

		AfterEach([=, this]()
		{
			ContentObject = nullptr;
		});

		It("should deserialize ids and version properly", [=, this]()
		{
			ContentObject->FromJson(FullObject);

			TestEqual("Id deserialized correctly", ContentObject->Id, TestId);
			TestEqual("Version deserialized correctly", ContentObject->Version, TestVersion);
		});

		It("should deserialize primitives properly", [=, this]()
		{
			ContentObject->FromJson(FullObject);
			TestEqual("Value deserialized correctly", ContentObject->Value, TestValueAInt);
		});

		It("should deserialize semantic types properly", [=, this]()
		{
			ContentObject->FromJson(FullObject);
			TestEqual("BeamCid deserialized correctly", ContentObject->BeamCid, FBeamCid{TestBeamCid});
		});

		It("should deserialize TArray<> properly", [=, this]()
		{
			ContentObject->FromJson(FullObject);
			TestEqual("U8 Array deserialized correctly", ContentObject->ArrayOfU8, TArray{static_cast<uint8>(TestValueAInt), static_cast<uint8>(TestValueBInt)});
			TestEqual("String Array deserialized correctly", ContentObject->ArrayOfString, TArray{TestValueA, TestValueB});
			TestEqual("Semantic Type Array deserialized correctly", ContentObject->ArrayOfBeamCid[0], FBeamCid{TestBeamCid});
		});

		It("should deserialize TMap<FString,> properly", [=, this]()
		{
			ContentObject->FromJson(FullObject);

			TestEqual("U8 Map deserialized correctly", ContentObject->MapOfU8.FindRef(TEXT("a")), TestValueAInt);
			TestEqual("FString Map deserialized correctly", ContentObject->MapOfString.FindRef(TEXT("a")), TestValueA);
			TestEqual("Semantic Type Map deserialized correctly", ContentObject->MapOfBeamCid.FindRef(TEXT("a")), FBeamCid{TestBeamCid});
		});

		It("should deserialize BeamArrays properly", [=, this]()
		{
			ContentObject->FromJson(FullObject);
			TestEqual("FArrayOfString deserialized correctly", ContentObject->BeamArrayOfString.Values[0], TestValueA);
			TestEqual("TArray<FArrayOfString> deserialized correctly", ContentObject->ArrayOfArrayOfString[0].Values[0], TestValueA);
			TestEqual("TArray<FArrayOfString> deserialized correctly", ContentObject->ArrayOfArrayOfString[0].Values[1], TestValueB);
			TestEqual("TArray<FMapOfString> deserialized correctly", ContentObject->ArrayOfMapOfString[0].Values.FindRef(TEXT("a")), TestValueA);
			TestEqual("TArray<FMapOfString> deserialized correctly", ContentObject->ArrayOfMapOfString[1].Values.FindRef(TEXT("a")), TestValueB);
		});

		It("should deserialize BeamMaps properly", [=, this]()
		{
			ContentObject->FromJson(FullObject);
			TestEqual("FMapOfString deserialized correctly", ContentObject->BeamMapOfString.Values.FindRef(TEXT("a")), TestValueA);
			TestEqual("TMap<FString, FArrayOfString> deserialized correctly", ContentObject->MapOfArrayOfString.FindRef("a").Values[0], TestValueA);
			TestEqual("TMap<FString, FArrayOfString> deserialized correctly", ContentObject->MapOfArrayOfString.FindRef("a").Values[1], TestValueB);
			TestEqual("TMap<FString, FMapOfString> deserialized correctly", ContentObject->MapOfMapOfString.FindRef("a").Values.FindRef("a"), TestValueA);
		});


		It("should deserialize BeamOptionals properly", [=, this]()
		{
			ContentObject->FromJson(FullObject);
			TestEqual("Optional of Primitive deserialized correctly", ContentObject->BeamOptionalBool.Val, false);
			TestEqual("Optional of semantic type deserialized correctly", ContentObject->BeamOptionalBeamCid.Val.AsString, TestBeamCid);

			TestEqual("Optional of TArray<int> deserialized correctly", ContentObject->BeamOptionalArrayOfInt32.Val[0], TestValueAInt);
			TestEqual("Optional of TArray<int> deserialized correctly", ContentObject->BeamOptionalArrayOfInt32.Val[1], TestValueBInt);

			TestEqual("Optional of TMap<FString, int> deserialized correctly", ContentObject->BeamOptionalMapOfInt64.Val.FindRef("a"), TestValueAInt);

			TestEqual("Optional of TArray of Semantic Type deserialized correctly", ContentObject->BeamOptionalArrayOfBeamPid.Val[0].AsString, TestBeamCid);
		});

		It("should deserialize BeamOptionals as unset when they are not in the JSON", [=, this]()
		{
			ContentObject->FromJson(WithoutOptionals);
			TestEqual("Optional of Primitive deserialized correctly", ContentObject->BeamOptionalBool.IsSet, false);
			TestEqual("Optional of Primitive deserialized correctly", ContentObject->BeamOptionalBeamCid.IsSet, false);
			TestEqual("Optional of Primitive deserialized correctly", ContentObject->BeamOptionalArrayOfInt32.IsSet, false);
			TestEqual("Optional of Primitive deserialized correctly", ContentObject->BeamOptionalMapOfInt64.IsSet, false);
			TestEqual("Optional of Primitive deserialized correctly", ContentObject->BeamOptionalArrayOfBeamPid.IsSet, false);
		});
	});
}
