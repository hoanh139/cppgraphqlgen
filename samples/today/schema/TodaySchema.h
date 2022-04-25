// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WARNING! Do not edit this file manually, your changes will be overwritten.

#pragma once

#ifndef TODAYSCHEMA_H
#define TODAYSCHEMA_H

#include "graphqlservice/internal/Schema.h"

// Check if the library version is compatible with schemagen 4.2.0
static_assert(graphql::internal::MajorVersion == 4, "regenerate with schemagen: major version mismatch");
static_assert(graphql::internal::MinorVersion == 2, "regenerate with schemagen: minor version mismatch");

#include <array>
#include <memory>
#include <string>
#include <string_view>

namespace graphql {
namespace today {

enum class TaskState
{
	New,
	Started,
	Complete,
	Unassigned
};

constexpr auto getTaskStateNames() noexcept
{
	using namespace std::literals;

	return std::array<std::string_view, 4> {
		R"gql(New)gql"sv,
		R"gql(Started)gql"sv,
		R"gql(Complete)gql"sv,
		R"gql(Unassigned)gql"sv
	};
}

struct CompleteTaskInput
{
	response::IdType id {};
	std::optional<TaskState> testTaskState {};
	std::optional<bool> isComplete {};
	std::optional<std::string> clientMutationId {};
};

struct ThirdNestedInput
{
	response::IdType id {};
};

struct FourthNestedInput
{
	response::IdType id {};
};

struct IncludeNullableSelfInput
{
	std::unique_ptr<IncludeNullableSelfInput> self {};
};

struct IncludeNonNullableListSelfInput
{
	std::vector<IncludeNonNullableListSelfInput> selves {};
};

struct StringOperationFilterInput
{
	std::optional<std::vector<StringOperationFilterInput>> and_ {};
	std::optional<std::vector<StringOperationFilterInput>> or_ {};
	std::optional<std::string> equal {};
	std::optional<std::string> notEqual {};
	std::optional<std::string> contains {};
	std::optional<std::string> notContains {};
	std::optional<std::vector<std::string>> in {};
	std::optional<std::vector<std::string>> notIn {};
	std::optional<std::string> startsWith {};
	std::optional<std::string> notStartsWith {};
	std::optional<std::string> endsWith {};
	std::optional<std::string> notEndsWith {};
};

struct SecondNestedInput
{
	response::IdType id {};
	ThirdNestedInput third {};
};

struct ForwardDeclaredInput
{
	std::unique_ptr<IncludeNullableSelfInput> nullableSelf {};
	IncludeNonNullableListSelfInput listSelves {};
};

struct FirstNestedInput
{
	response::IdType id {};
	SecondNestedInput second {};
	ThirdNestedInput third {};
};

namespace object {

class Node;

class UnionType;

class Query;
class PageInfo;
class AppointmentEdge;
class AppointmentConnection;
class TaskEdge;
class TaskConnection;
class FolderEdge;
class FolderConnection;
class CompleteTaskPayload;
class Mutation;
class Subscription;
class Appointment;
class Task;
class Folder;
class NestedType;
class Expensive;

} // namespace object

class Operations final
	: public service::Request
{
public:
	explicit Operations(std::shared_ptr<object::Query> query, std::shared_ptr<object::Mutation> mutation, std::shared_ptr<object::Subscription> subscription);

	template <class TQuery, class TMutation, class TSubscription>
	explicit Operations(std::shared_ptr<TQuery> query, std::shared_ptr<TMutation> mutation, std::shared_ptr<TSubscription> subscription)
		: Operations { std::make_shared<object::Query>(std::move(query)), std::make_shared<object::Mutation>(std::move(mutation)), std::make_shared<object::Subscription>(std::move(subscription)) }
	{
	}

private:
	std::shared_ptr<object::Query> _query;
	std::shared_ptr<object::Mutation> _mutation;
	std::shared_ptr<object::Subscription> _subscription;
};

void AddNodeDetails(const std::shared_ptr<schema::InterfaceType>& typeNode, const std::shared_ptr<schema::Schema>& schema);

void AddUnionTypeDetails(const std::shared_ptr<schema::UnionType>& typeUnionType, const std::shared_ptr<schema::Schema>& schema);

void AddQueryDetails(const std::shared_ptr<schema::ObjectType>& typeQuery, const std::shared_ptr<schema::Schema>& schema);
void AddPageInfoDetails(const std::shared_ptr<schema::ObjectType>& typePageInfo, const std::shared_ptr<schema::Schema>& schema);
void AddAppointmentEdgeDetails(const std::shared_ptr<schema::ObjectType>& typeAppointmentEdge, const std::shared_ptr<schema::Schema>& schema);
void AddAppointmentConnectionDetails(const std::shared_ptr<schema::ObjectType>& typeAppointmentConnection, const std::shared_ptr<schema::Schema>& schema);
void AddTaskEdgeDetails(const std::shared_ptr<schema::ObjectType>& typeTaskEdge, const std::shared_ptr<schema::Schema>& schema);
void AddTaskConnectionDetails(const std::shared_ptr<schema::ObjectType>& typeTaskConnection, const std::shared_ptr<schema::Schema>& schema);
void AddFolderEdgeDetails(const std::shared_ptr<schema::ObjectType>& typeFolderEdge, const std::shared_ptr<schema::Schema>& schema);
void AddFolderConnectionDetails(const std::shared_ptr<schema::ObjectType>& typeFolderConnection, const std::shared_ptr<schema::Schema>& schema);
void AddCompleteTaskPayloadDetails(const std::shared_ptr<schema::ObjectType>& typeCompleteTaskPayload, const std::shared_ptr<schema::Schema>& schema);
void AddMutationDetails(const std::shared_ptr<schema::ObjectType>& typeMutation, const std::shared_ptr<schema::Schema>& schema);
void AddSubscriptionDetails(const std::shared_ptr<schema::ObjectType>& typeSubscription, const std::shared_ptr<schema::Schema>& schema);
void AddAppointmentDetails(const std::shared_ptr<schema::ObjectType>& typeAppointment, const std::shared_ptr<schema::Schema>& schema);
void AddTaskDetails(const std::shared_ptr<schema::ObjectType>& typeTask, const std::shared_ptr<schema::Schema>& schema);
void AddFolderDetails(const std::shared_ptr<schema::ObjectType>& typeFolder, const std::shared_ptr<schema::Schema>& schema);
void AddNestedTypeDetails(const std::shared_ptr<schema::ObjectType>& typeNestedType, const std::shared_ptr<schema::Schema>& schema);
void AddExpensiveDetails(const std::shared_ptr<schema::ObjectType>& typeExpensive, const std::shared_ptr<schema::Schema>& schema);

std::shared_ptr<schema::Schema> GetSchema();

} // namespace today

namespace service {

template <>
constexpr bool isInputType<today::CompleteTaskInput>() noexcept
{
	return true;
}

template <>
constexpr bool isInputType<today::ThirdNestedInput>() noexcept
{
	return true;
}

template <>
constexpr bool isInputType<today::FourthNestedInput>() noexcept
{
	return true;
}

template <>
constexpr bool isInputType<today::IncludeNullableSelfInput>() noexcept
{
	return true;
}

template <>
constexpr bool isInputType<today::IncludeNonNullableListSelfInput>() noexcept
{
	return true;
}

template <>
constexpr bool isInputType<today::StringOperationFilterInput>() noexcept
{
	return true;
}

template <>
constexpr bool isInputType<today::SecondNestedInput>() noexcept
{
	return true;
}

template <>
constexpr bool isInputType<today::ForwardDeclaredInput>() noexcept
{
	return true;
}

template <>
constexpr bool isInputType<today::FirstNestedInput>() noexcept
{
	return true;
}

} // namespace service
} // namespace graphql

#endif // TODAYSCHEMA_H
