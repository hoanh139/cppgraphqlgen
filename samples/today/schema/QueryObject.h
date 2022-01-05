// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WARNING! Do not edit this file manually, your changes will be overwritten.

#pragma once

#ifndef QUERYOBJECT_H
#define QUERYOBJECT_H

#include "TodaySchema.h"

namespace graphql::today::object {
namespace methods::QueryHas {

template <class TImpl>
concept getNodeWithParams = requires (TImpl impl, service::FieldParams params, response::IdType idArg)
{
	{ service::AwaitableObject<std::shared_ptr<Node>> { impl.getNode(std::move(params), std::move(idArg)) } };
};

template <class TImpl>
concept getNode = requires (TImpl impl, response::IdType idArg)
{
	{ service::AwaitableObject<std::shared_ptr<Node>> { impl.getNode(std::move(idArg)) } };
};

template <class TImpl>
concept getAppointmentsWithParams = requires (TImpl impl, service::FieldParams params, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg)
{
	{ service::AwaitableObject<std::shared_ptr<AppointmentConnection>> { impl.getAppointments(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept getAppointments = requires (TImpl impl, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg)
{
	{ service::AwaitableObject<std::shared_ptr<AppointmentConnection>> { impl.getAppointments(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept getTasksWithParams = requires (TImpl impl, service::FieldParams params, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg)
{
	{ service::AwaitableObject<std::shared_ptr<TaskConnection>> { impl.getTasks(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept getTasks = requires (TImpl impl, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg)
{
	{ service::AwaitableObject<std::shared_ptr<TaskConnection>> { impl.getTasks(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept getUnreadCountsWithParams = requires (TImpl impl, service::FieldParams params, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg)
{
	{ service::AwaitableObject<std::shared_ptr<FolderConnection>> { impl.getUnreadCounts(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept getUnreadCounts = requires (TImpl impl, std::optional<int> firstArg, std::optional<response::Value> afterArg, std::optional<int> lastArg, std::optional<response::Value> beforeArg)
{
	{ service::AwaitableObject<std::shared_ptr<FolderConnection>> { impl.getUnreadCounts(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) } };
};

template <class TImpl>
concept getAppointmentsByIdWithParams = requires (TImpl impl, service::FieldParams params, std::vector<response::IdType> idsArg)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<Appointment>>> { impl.getAppointmentsById(std::move(params), std::move(idsArg)) } };
};

template <class TImpl>
concept getAppointmentsById = requires (TImpl impl, std::vector<response::IdType> idsArg)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<Appointment>>> { impl.getAppointmentsById(std::move(idsArg)) } };
};

template <class TImpl>
concept getTasksByIdWithParams = requires (TImpl impl, service::FieldParams params, std::vector<response::IdType> idsArg)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<Task>>> { impl.getTasksById(std::move(params), std::move(idsArg)) } };
};

template <class TImpl>
concept getTasksById = requires (TImpl impl, std::vector<response::IdType> idsArg)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<Task>>> { impl.getTasksById(std::move(idsArg)) } };
};

template <class TImpl>
concept getUnreadCountsByIdWithParams = requires (TImpl impl, service::FieldParams params, std::vector<response::IdType> idsArg)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<Folder>>> { impl.getUnreadCountsById(std::move(params), std::move(idsArg)) } };
};

template <class TImpl>
concept getUnreadCountsById = requires (TImpl impl, std::vector<response::IdType> idsArg)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<Folder>>> { impl.getUnreadCountsById(std::move(idsArg)) } };
};

template <class TImpl>
concept getNestedWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableObject<std::shared_ptr<NestedType>> { impl.getNested(std::move(params)) } };
};

template <class TImpl>
concept getNested = requires (TImpl impl)
{
	{ service::AwaitableObject<std::shared_ptr<NestedType>> { impl.getNested() } };
};

template <class TImpl>
concept getUnimplementedWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableScalar<std::string> { impl.getUnimplemented(std::move(params)) } };
};

template <class TImpl>
concept getUnimplemented = requires (TImpl impl)
{
	{ service::AwaitableScalar<std::string> { impl.getUnimplemented() } };
};

template <class TImpl>
concept getExpensiveWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<Expensive>>> { impl.getExpensive(std::move(params)) } };
};

template <class TImpl>
concept getExpensive = requires (TImpl impl)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<Expensive>>> { impl.getExpensive() } };
};

template <class TImpl>
concept getTestTaskStateWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableScalar<TaskState> { impl.getTestTaskState(std::move(params)) } };
};

template <class TImpl>
concept getTestTaskState = requires (TImpl impl)
{
	{ service::AwaitableScalar<TaskState> { impl.getTestTaskState() } };
};

template <class TImpl>
concept getAnyTypeWithParams = requires (TImpl impl, service::FieldParams params, std::vector<response::IdType> idsArg)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<UnionType>>> { impl.getAnyType(std::move(params), std::move(idsArg)) } };
};

template <class TImpl>
concept getAnyType = requires (TImpl impl, std::vector<response::IdType> idsArg)
{
	{ service::AwaitableObject<std::vector<std::shared_ptr<UnionType>>> { impl.getAnyType(std::move(idsArg)) } };
};

template <class TImpl>
concept beginSelectionSet = requires (TImpl impl, const service::SelectionSetParams params)
{
	{ impl.beginSelectionSet(params) };
};

template <class TImpl>
concept endSelectionSet = requires (TImpl impl, const service::SelectionSetParams params)
{
	{ impl.endSelectionSet(params) };
};

} // namespace methods::QueryHas

class Query
	: public service::Object
{
private:
	service::AwaitableResolver resolveNode(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveAppointments(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveTasks(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveUnreadCounts(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveAppointmentsById(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveTasksById(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveUnreadCountsById(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveNested(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveUnimplemented(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveExpensive(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveTestTaskState(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveAnyType(service::ResolverParams&& params) const;

	service::AwaitableResolver resolve_typename(service::ResolverParams&& params) const;
	service::AwaitableResolver resolve_schema(service::ResolverParams&& params) const;
	service::AwaitableResolver resolve_type(service::ResolverParams&& params) const;

	std::shared_ptr<schema::Schema> _schema;

	struct Concept
	{
		virtual ~Concept() = default;

		virtual void beginSelectionSet(const service::SelectionSetParams& params) const = 0;
		virtual void endSelectionSet(const service::SelectionSetParams& params) const = 0;

		virtual service::AwaitableObject<std::shared_ptr<Node>> getNode(service::FieldParams&& params, response::IdType&& idArg) const = 0;
		virtual service::AwaitableObject<std::shared_ptr<AppointmentConnection>> getAppointments(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const = 0;
		virtual service::AwaitableObject<std::shared_ptr<TaskConnection>> getTasks(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const = 0;
		virtual service::AwaitableObject<std::shared_ptr<FolderConnection>> getUnreadCounts(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const = 0;
		virtual service::AwaitableObject<std::vector<std::shared_ptr<Appointment>>> getAppointmentsById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const = 0;
		virtual service::AwaitableObject<std::vector<std::shared_ptr<Task>>> getTasksById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const = 0;
		virtual service::AwaitableObject<std::vector<std::shared_ptr<Folder>>> getUnreadCountsById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const = 0;
		virtual service::AwaitableObject<std::shared_ptr<NestedType>> getNested(service::FieldParams&& params) const = 0;
		virtual service::AwaitableScalar<std::string> getUnimplemented(service::FieldParams&& params) const = 0;
		virtual service::AwaitableObject<std::vector<std::shared_ptr<Expensive>>> getExpensive(service::FieldParams&& params) const = 0;
		virtual service::AwaitableScalar<TaskState> getTestTaskState(service::FieldParams&& params) const = 0;
		virtual service::AwaitableObject<std::vector<std::shared_ptr<UnionType>>> getAnyType(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const = 0;
	};

	template <class T>
	struct Model
		: Concept
	{
		Model(std::shared_ptr<T>&& pimpl) noexcept
			: _pimpl { std::move(pimpl) }
		{
		}

		service::AwaitableObject<std::shared_ptr<Node>> getNode(service::FieldParams&& params, response::IdType&& idArg) const final
		{
			if constexpr (methods::QueryHas::getNodeWithParams<T>)
			{
				return { _pimpl->getNode(std::move(params), std::move(idArg)) };
			}
			else if constexpr (methods::QueryHas::getNode<T>)
			{
				return { _pimpl->getNode(std::move(idArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getNode is not implemented)ex");
			}
		}

		service::AwaitableObject<std::shared_ptr<AppointmentConnection>> getAppointments(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const final
		{
			if constexpr (methods::QueryHas::getAppointmentsWithParams<T>)
			{
				return { _pimpl->getAppointments(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else if constexpr (methods::QueryHas::getAppointments<T>)
			{
				return { _pimpl->getAppointments(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getAppointments is not implemented)ex");
			}
		}

		service::AwaitableObject<std::shared_ptr<TaskConnection>> getTasks(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const final
		{
			if constexpr (methods::QueryHas::getTasksWithParams<T>)
			{
				return { _pimpl->getTasks(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else if constexpr (methods::QueryHas::getTasks<T>)
			{
				return { _pimpl->getTasks(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getTasks is not implemented)ex");
			}
		}

		service::AwaitableObject<std::shared_ptr<FolderConnection>> getUnreadCounts(service::FieldParams&& params, std::optional<int>&& firstArg, std::optional<response::Value>&& afterArg, std::optional<int>&& lastArg, std::optional<response::Value>&& beforeArg) const final
		{
			if constexpr (methods::QueryHas::getUnreadCountsWithParams<T>)
			{
				return { _pimpl->getUnreadCounts(std::move(params), std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else if constexpr (methods::QueryHas::getUnreadCounts<T>)
			{
				return { _pimpl->getUnreadCounts(std::move(firstArg), std::move(afterArg), std::move(lastArg), std::move(beforeArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getUnreadCounts is not implemented)ex");
			}
		}

		service::AwaitableObject<std::vector<std::shared_ptr<Appointment>>> getAppointmentsById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const final
		{
			if constexpr (methods::QueryHas::getAppointmentsByIdWithParams<T>)
			{
				return { _pimpl->getAppointmentsById(std::move(params), std::move(idsArg)) };
			}
			else if constexpr (methods::QueryHas::getAppointmentsById<T>)
			{
				return { _pimpl->getAppointmentsById(std::move(idsArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getAppointmentsById is not implemented)ex");
			}
		}

		service::AwaitableObject<std::vector<std::shared_ptr<Task>>> getTasksById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const final
		{
			if constexpr (methods::QueryHas::getTasksByIdWithParams<T>)
			{
				return { _pimpl->getTasksById(std::move(params), std::move(idsArg)) };
			}
			else if constexpr (methods::QueryHas::getTasksById<T>)
			{
				return { _pimpl->getTasksById(std::move(idsArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getTasksById is not implemented)ex");
			}
		}

		service::AwaitableObject<std::vector<std::shared_ptr<Folder>>> getUnreadCountsById(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const final
		{
			if constexpr (methods::QueryHas::getUnreadCountsByIdWithParams<T>)
			{
				return { _pimpl->getUnreadCountsById(std::move(params), std::move(idsArg)) };
			}
			else if constexpr (methods::QueryHas::getUnreadCountsById<T>)
			{
				return { _pimpl->getUnreadCountsById(std::move(idsArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getUnreadCountsById is not implemented)ex");
			}
		}

		service::AwaitableObject<std::shared_ptr<NestedType>> getNested(service::FieldParams&& params) const final
		{
			if constexpr (methods::QueryHas::getNestedWithParams<T>)
			{
				return { _pimpl->getNested(std::move(params)) };
			}
			else if constexpr (methods::QueryHas::getNested<T>)
			{
				return { _pimpl->getNested() };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getNested is not implemented)ex");
			}
		}

		service::AwaitableScalar<std::string> getUnimplemented(service::FieldParams&& params) const final
		{
			if constexpr (methods::QueryHas::getUnimplementedWithParams<T>)
			{
				return { _pimpl->getUnimplemented(std::move(params)) };
			}
			else if constexpr (methods::QueryHas::getUnimplemented<T>)
			{
				return { _pimpl->getUnimplemented() };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getUnimplemented is not implemented)ex");
			}
		}

		service::AwaitableObject<std::vector<std::shared_ptr<Expensive>>> getExpensive(service::FieldParams&& params) const final
		{
			if constexpr (methods::QueryHas::getExpensiveWithParams<T>)
			{
				return { _pimpl->getExpensive(std::move(params)) };
			}
			else if constexpr (methods::QueryHas::getExpensive<T>)
			{
				return { _pimpl->getExpensive() };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getExpensive is not implemented)ex");
			}
		}

		service::AwaitableScalar<TaskState> getTestTaskState(service::FieldParams&& params) const final
		{
			if constexpr (methods::QueryHas::getTestTaskStateWithParams<T>)
			{
				return { _pimpl->getTestTaskState(std::move(params)) };
			}
			else if constexpr (methods::QueryHas::getTestTaskState<T>)
			{
				return { _pimpl->getTestTaskState() };
			}
			else
			{
				throw std::runtime_error(R"ex(Query::getTestTaskState is not implemented)ex");
			}
		}

		service::AwaitableObject<std::vector<std::shared_ptr<UnionType>>> getAnyType(service::FieldParams&& params, std::vector<response::IdType>&& idsArg) const final
		{
			if constexpr (methods::QueryHas::getAnyTypeWithParams<T>)
			{
				return { _pimpl->getAnyType(std::move(params), std::move(idsArg)) };
			}
			else if constexpr (methods::QueryHas::getAnyType<T>)
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
			if constexpr (methods::QueryHas::beginSelectionSet<T>)
			{
				_pimpl->beginSelectionSet(params);
			}
		}

		void endSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::QueryHas::endSelectionSet<T>)
			{
				_pimpl->endSelectionSet(params);
			}
		}

	private:
		const std::shared_ptr<T> _pimpl;
	};

	Query(std::unique_ptr<Concept>&& pimpl) noexcept;

	service::TypeNames getTypeNames() const noexcept;
	service::ResolverMap getResolvers() const noexcept;

	void beginSelectionSet(const service::SelectionSetParams& params) const final;
	void endSelectionSet(const service::SelectionSetParams& params) const final;

	const std::unique_ptr<Concept> _pimpl;

public:
	template <class T>
	Query(std::shared_ptr<T> pimpl) noexcept
		: Query { std::unique_ptr<Concept> { std::make_unique<Model<T>>(std::move(pimpl)) } }
	{
	}
};

} // namespace graphql::today::object

#endif // QUERYOBJECT_H
