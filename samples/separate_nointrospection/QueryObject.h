// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WARNING! Do not edit this file manually, your changes will be overwritten.

#pragma once

#ifndef QUERYOBJECT_H
#define QUERYOBJECT_H

#include "TodaySchema.h"

namespace graphql::today::object {
namespace methods::QueryMethod {

template <class TImpl>
concept WithParamsNode = requires (TImpl impl, service::FieldParams params, response::IdType idArg) 
{
	{ service::FieldResult<std::shared_ptr<service::Object>> { impl.getNode(std::move(params), std::move(idArg)) } };
};

template <class TImpl>
concept NoParamsNode = requires (TImpl impl, response::IdType idArg) 
{
	{ service::FieldResult<std::shared_ptr<service::Object>> { impl.getNode(std::move(idArg)) } };
};

template <class TImpl>
concept WithParamsAppointments = requires (TImpl impl, service::FieldParams params, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg) 
{
	{ service::FieldResult<std::shared_ptr<AppointmentConnection>> { impl.getAppointments(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept NoParamsAppointments = requires (TImpl impl, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg) 
{
	{ service::FieldResult<std::shared_ptr<AppointmentConnection>> { impl.getAppointments(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept WithParamsTasks = requires (TImpl impl, service::FieldParams params, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg) 
{
	{ service::FieldResult<std::shared_ptr<TaskConnection>> { impl.getTasks(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept NoParamsTasks = requires (TImpl impl, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg) 
{
	{ service::FieldResult<std::shared_ptr<TaskConnection>> { impl.getTasks(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept WithParamsUnreadCounts = requires (TImpl impl, service::FieldParams params, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg) 
{
	{ service::FieldResult<std::shared_ptr<FolderConnection>> { impl.getUnreadCounts(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept NoParamsUnreadCounts = requires (TImpl impl, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg) 
{
	{ service::FieldResult<std::shared_ptr<FolderConnection>> { impl.getUnreadCounts(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept WithParamsAppointmentsById = requires (TImpl impl, service::FieldParams params, std::vector<response::IdType> idsArg) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<Appointment>>> { impl.getAppointmentsById(std::move(params), std::move(idsArg)) } };
};

template <class TImpl>
concept NoParamsAppointmentsById = requires (TImpl impl, std::vector<response::IdType> idsArg) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<Appointment>>> { impl.getAppointmentsById(std::move(idsArg)) } };
};

template <class TImpl>
concept WithParamsTasksById = requires (TImpl impl, service::FieldParams params, std::vector<response::IdType> idsArg) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<Task>>> { impl.getTasksById(std::move(params), std::move(idsArg)) } };
};

template <class TImpl>
concept NoParamsTasksById = requires (TImpl impl, std::vector<response::IdType> idsArg) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<Task>>> { impl.getTasksById(std::move(idsArg)) } };
};

template <class TImpl>
concept WithParamsUnreadCountsById = requires (TImpl impl, service::FieldParams params, std::vector<response::IdType> idsArg) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<Folder>>> { impl.getUnreadCountsById(std::move(params), std::move(idsArg)) } };
};

template <class TImpl>
concept NoParamsUnreadCountsById = requires (TImpl impl, std::vector<response::IdType> idsArg) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<Folder>>> { impl.getUnreadCountsById(std::move(idsArg)) } };
};

template <class TImpl>
concept WithParamsNested = requires (TImpl impl, service::FieldParams params) 
{
	{ service::FieldResult<std::shared_ptr<NestedType>> { impl.getNested(std::move(params)) } };
};

template <class TImpl>
concept NoParamsNested = requires (TImpl impl) 
{
	{ service::FieldResult<std::shared_ptr<NestedType>> { impl.getNested() } };
};

template <class TImpl>
concept WithParamsUnimplemented = requires (TImpl impl, service::FieldParams params) 
{
	{ service::FieldResult<std::string> { impl.getUnimplemented(std::move(params)) } };
};

template <class TImpl>
concept NoParamsUnimplemented = requires (TImpl impl) 
{
	{ service::FieldResult<std::string> { impl.getUnimplemented() } };
};

template <class TImpl>
concept WithParamsExpensive = requires (TImpl impl, service::FieldParams params) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<Expensive>>> { impl.getExpensive(std::move(params)) } };
};

template <class TImpl>
concept NoParamsExpensive = requires (TImpl impl) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<Expensive>>> { impl.getExpensive() } };
};

template <class TImpl>
concept WithParamsTestTaskState = requires (TImpl impl, service::FieldParams params) 
{
	{ service::FieldResult<TaskState> { impl.getTestTaskState(std::move(params)) } };
};

template <class TImpl>
concept NoParamsTestTaskState = requires (TImpl impl) 
{
	{ service::FieldResult<TaskState> { impl.getTestTaskState() } };
};

template <class TImpl>
concept WithParamsAnyType = requires (TImpl impl, service::FieldParams params, std::vector<response::IdType> idsArg) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<service::Object>>> { impl.getAnyType(std::move(params), std::move(idsArg)) } };
};

template <class TImpl>
concept NoParamsAnyType = requires (TImpl impl, std::vector<response::IdType> idsArg) 
{
	{ service::FieldResult<std::vector<std::shared_ptr<service::Object>>> { impl.getAnyType(std::move(idsArg)) } };
};

template <class TImpl>
concept HasBeginSelectionSet = requires (TImpl impl, const service::SelectionSetParams params) 
{
	{ impl.beginSelectionSet(params) };
};

template <class TImpl>
concept HasEndSelectionSet = requires (TImpl impl, const service::SelectionSetParams params) 
{
	{ impl.endSelectionSet(params) };
};

} // namespace methods::QueryMethod

class Query
	: public service::Object
{
private:
	service::AwaitableResolver resolveNode(service::ResolverParams&& params);
	service::AwaitableResolver resolveAppointments(service::ResolverParams&& params);
	service::AwaitableResolver resolveTasks(service::ResolverParams&& params);
	service::AwaitableResolver resolveUnreadCounts(service::ResolverParams&& params);
	service::AwaitableResolver resolveAppointmentsById(service::ResolverParams&& params);
	service::AwaitableResolver resolveTasksById(service::ResolverParams&& params);
	service::AwaitableResolver resolveUnreadCountsById(service::ResolverParams&& params);
	service::AwaitableResolver resolveNested(service::ResolverParams&& params);
	service::AwaitableResolver resolveUnimplemented(service::ResolverParams&& params);
	service::AwaitableResolver resolveExpensive(service::ResolverParams&& params);
	service::AwaitableResolver resolveTestTaskState(service::ResolverParams&& params);
	service::AwaitableResolver resolveAnyType(service::ResolverParams&& params);

	service::AwaitableResolver resolve_typename(service::ResolverParams&& params);

	struct Concept
	{
		virtual ~Concept() = default;

		virtual void beginSelectionSet(const service::SelectionSetParams& params) const = 0;
		virtual void endSelectionSet(const service::SelectionSetParams& params) const = 0;

		virtual service::FieldResult<std::shared_ptr<service::Object>> getNode(service::FieldParams&& params, response::IdType&& idArg) const = 0;
		virtual service::FieldResult<std::shared_ptr<AppointmentConnection>> getAppointments(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const = 0;
		virtual service::FieldResult<std::shared_ptr<TaskConnection>> getTasks(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const = 0;
		virtual service::FieldResult<std::shared_ptr<FolderConnection>> getUnreadCounts(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const = 0;
		virtual service::FieldResult<std::vector<std::shared_ptr<Appointment>>> getAppointmentsById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const = 0;
		virtual service::FieldResult<std::vector<std::shared_ptr<Task>>> getTasksById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const = 0;
		virtual service::FieldResult<std::vector<std::shared_ptr<Folder>>> getUnreadCountsById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const = 0;
		virtual service::FieldResult<std::shared_ptr<NestedType>> getNested(service::FieldParams&& params) const = 0;
		virtual service::FieldResult<std::string> getUnimplemented(service::FieldParams&& params) const = 0;
		virtual service::FieldResult<std::vector<std::shared_ptr<Expensive>>> getExpensive(service::FieldParams&& params) const = 0;
		virtual service::FieldResult<TaskState> getTestTaskState(service::FieldParams&& params) const = 0;
		virtual service::FieldResult<std::vector<std::shared_ptr<service::Object>>> getAnyType(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const = 0;
	};

	template <class T>
	struct Model
		: Concept
	{
		Model(std::shared_ptr<T>&& pimpl) noexcept
			: _pimpl { std::move(pimpl) }
		{
		}

		service::FieldResult<std::shared_ptr<service::Object>> getNode(service::FieldParams&& params, response::IdType&& idArg) const final
		{
			if constexpr (methods::QueryMethod::WithParamsNode<T>)
			{
				return { _pimpl->getNode(std::move(params), std::move(idArg)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsNode<T>)
			{
				return { _pimpl->getNode(std::move(idArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getNode is not implemented)ex");
			}
		}

		service::FieldResult<std::shared_ptr<AppointmentConnection>> getAppointments(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const final
		{
			if constexpr (methods::QueryMethod::WithParamsAppointments<T>)
			{
				return { _pimpl->getAppointments(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsAppointments<T>)
			{
				return { _pimpl->getAppointments(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getAppointments is not implemented)ex");
			}
		}

		service::FieldResult<std::shared_ptr<TaskConnection>> getTasks(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const final
		{
			if constexpr (methods::QueryMethod::WithParamsTasks<T>)
			{
				return { _pimpl->getTasks(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsTasks<T>)
			{
				return { _pimpl->getTasks(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getTasks is not implemented)ex");
			}
		}

		service::FieldResult<std::shared_ptr<FolderConnection>> getUnreadCounts(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const final
		{
			if constexpr (methods::QueryMethod::WithParamsUnreadCounts<T>)
			{
				return { _pimpl->getUnreadCounts(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsUnreadCounts<T>)
			{
				return { _pimpl->getUnreadCounts(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getUnreadCounts is not implemented)ex");
			}
		}

		service::FieldResult<std::vector<std::shared_ptr<Appointment>>> getAppointmentsById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const final
		{
			if constexpr (methods::QueryMethod::WithParamsAppointmentsById<T>)
			{
				return { _pimpl->getAppointmentsById(std::move(params), std::move(idsArg)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsAppointmentsById<T>)
			{
				return { _pimpl->getAppointmentsById(std::move(idsArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getAppointmentsById is not implemented)ex");
			}
		}

		service::FieldResult<std::vector<std::shared_ptr<Task>>> getTasksById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const final
		{
			if constexpr (methods::QueryMethod::WithParamsTasksById<T>)
			{
				return { _pimpl->getTasksById(std::move(params), std::move(idsArg)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsTasksById<T>)
			{
				return { _pimpl->getTasksById(std::move(idsArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getTasksById is not implemented)ex");
			}
		}

		service::FieldResult<std::vector<std::shared_ptr<Folder>>> getUnreadCountsById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const final
		{
			if constexpr (methods::QueryMethod::WithParamsUnreadCountsById<T>)
			{
				return { _pimpl->getUnreadCountsById(std::move(params), std::move(idsArg)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsUnreadCountsById<T>)
			{
				return { _pimpl->getUnreadCountsById(std::move(idsArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getUnreadCountsById is not implemented)ex");
			}
		}

		service::FieldResult<std::shared_ptr<NestedType>> getNested(service::FieldParams&& params) const final
		{
			if constexpr (methods::QueryMethod::WithParamsNested<T>)
			{
				return { _pimpl->getNested(std::move(params)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsNested<T>)
			{
				return { _pimpl->getNested() };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getNested is not implemented)ex");
			}
		}

		service::FieldResult<std::string> getUnimplemented(service::FieldParams&& params) const final
		{
			if constexpr (methods::QueryMethod::WithParamsUnimplemented<T>)
			{
				return { _pimpl->getUnimplemented(std::move(params)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsUnimplemented<T>)
			{
				return { _pimpl->getUnimplemented() };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getUnimplemented is not implemented)ex");
			}
		}

		service::FieldResult<std::vector<std::shared_ptr<Expensive>>> getExpensive(service::FieldParams&& params) const final
		{
			if constexpr (methods::QueryMethod::WithParamsExpensive<T>)
			{
				return { _pimpl->getExpensive(std::move(params)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsExpensive<T>)
			{
				return { _pimpl->getExpensive() };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getExpensive is not implemented)ex");
			}
		}

		service::FieldResult<TaskState> getTestTaskState(service::FieldParams&& params) const final
		{
			if constexpr (methods::QueryMethod::WithParamsTestTaskState<T>)
			{
				return { _pimpl->getTestTaskState(std::move(params)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsTestTaskState<T>)
			{
				return { _pimpl->getTestTaskState() };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getTestTaskState is not implemented)ex");
			}
		}

		service::FieldResult<std::vector<std::shared_ptr<service::Object>>> getAnyType(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const final
		{
			if constexpr (methods::QueryMethod::WithParamsAnyType<T>)
			{
				return { _pimpl->getAnyType(std::move(params), std::move(idsArg)) };
			}
			else if constexpr (methods::QueryMethod::NoParamsAnyType<T>)
			{
				return { _pimpl->getAnyType(std::move(idsArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getAnyType is not implemented)ex");
			}
		}

		void beginSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::QueryMethod::HasBeginSelectionSet<T>)
			{
				_pimpl->beginSelectionSet(params);
			}
		}

		void endSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::QueryMethod::HasEndSelectionSet<T>)
			{
				_pimpl->endSelectionSet(params);
			}
		}

	private:
		const std::shared_ptr<T> _pimpl;
	};

	Query(std::unique_ptr<Concept>&& pimpl);

	void beginSelectionSet(const service::SelectionSetParams& params) const final;
	void endSelectionSet(const service::SelectionSetParams& params) const final;

	const std::unique_ptr<Concept> _pimpl;

public:
	template <class T>
	Query(std::shared_ptr<T> pimpl)
		: Query { std::unique_ptr<Concept> { std::make_unique<Model<T>>(std::move(pimpl)) } }
	{
	}
};

} // namespace graphql::today::object

#endif // QUERYOBJECT_H
