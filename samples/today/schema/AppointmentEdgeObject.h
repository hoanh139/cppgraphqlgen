// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WARNING! Do not edit this file manually, your changes will be overwritten.

#pragma once

#ifndef APPOINTMENTEDGEOBJECT_H
#define APPOINTMENTEDGEOBJECT_H

#include "TodaySchema.h"

namespace graphql::today::object {
namespace methods::AppointmentEdgeHas {

template <class TImpl>
concept getNodeWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableObject<std::shared_ptr<Appointment>> { impl.getNode(std::move(params)) } };
};

template <class TImpl>
concept getNode = requires (TImpl impl)
{
	{ service::AwaitableObject<std::shared_ptr<Appointment>> { impl.getNode() } };
};

template <class TImpl>
concept getCursorWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableScalar<response::Value> { impl.getCursor(std::move(params)) } };
};

template <class TImpl>
concept getCursor = requires (TImpl impl)
{
	{ service::AwaitableScalar<response::Value> { impl.getCursor() } };
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

} // namespace methods::AppointmentEdgeHas

class AppointmentEdge final
	: public service::Object
{
private:
	service::AwaitableResolver resolveNode(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveCursor(service::ResolverParams&& params) const;

	service::AwaitableResolver resolve_typename(service::ResolverParams&& params) const;

	struct Concept
	{
		virtual ~Concept() = default;

		virtual void beginSelectionSet(const service::SelectionSetParams& params) const = 0;
		virtual void endSelectionSet(const service::SelectionSetParams& params) const = 0;

		virtual service::AwaitableObject<std::shared_ptr<Appointment>> getNode(service::FieldParams&& params) const = 0;
		virtual service::AwaitableScalar<response::Value> getCursor(service::FieldParams&& params) const = 0;
	};

	template <class T>
	struct Model
		: Concept
	{
		Model(std::shared_ptr<T>&& pimpl) noexcept
			: _pimpl { std::move(pimpl) }
		{
		}

		service::AwaitableObject<std::shared_ptr<Appointment>> getNode(service::FieldParams&& params) const final
		{
			if constexpr (methods::AppointmentEdgeHas::getNodeWithParams<T>)
			{
				return { _pimpl->getNode(std::move(params)) };
			}
			else if constexpr (methods::AppointmentEdgeHas::getNode<T>)
			{
				return { _pimpl->getNode() };
			}
			else
			{
				throw std::runtime_error(R"ex(AppointmentEdge::getNode is not implemented)ex");
			}
		}

		service::AwaitableScalar<response::Value> getCursor(service::FieldParams&& params) const final
		{
			if constexpr (methods::AppointmentEdgeHas::getCursorWithParams<T>)
			{
				return { _pimpl->getCursor(std::move(params)) };
			}
			else if constexpr (methods::AppointmentEdgeHas::getCursor<T>)
			{
				return { _pimpl->getCursor() };
			}
			else
			{
				throw std::runtime_error(R"ex(AppointmentEdge::getCursor is not implemented)ex");
			}
		}

		void beginSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::AppointmentEdgeHas::beginSelectionSet<T>)
			{
				_pimpl->beginSelectionSet(params);
			}
		}

		void endSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::AppointmentEdgeHas::endSelectionSet<T>)
			{
				_pimpl->endSelectionSet(params);
			}
		}

	private:
		const std::shared_ptr<T> _pimpl;
	};

	AppointmentEdge(std::unique_ptr<const Concept>&& pimpl) noexcept;

	service::TypeNames getTypeNames() const noexcept;
	service::ResolverMap getResolvers() const noexcept;

	void beginSelectionSet(const service::SelectionSetParams& params) const final;
	void endSelectionSet(const service::SelectionSetParams& params) const final;

	const std::unique_ptr<const Concept> _pimpl;

public:
	template <class T>
	AppointmentEdge(std::shared_ptr<T> pimpl) noexcept
		: AppointmentEdge { std::unique_ptr<const Concept> { std::make_unique<Model<T>>(std::move(pimpl)) } }
	{
	}
};

} // namespace graphql::today::object

#endif // APPOINTMENTEDGEOBJECT_H
