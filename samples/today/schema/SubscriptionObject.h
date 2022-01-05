// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WARNING! Do not edit this file manually, your changes will be overwritten.

#pragma once

#ifndef SUBSCRIPTIONOBJECT_H
#define SUBSCRIPTIONOBJECT_H

#include "TodaySchema.h"

namespace graphql::today::object {
namespace methods::SubscriptionHas {

template <class TImpl>
concept getNextAppointmentChangeWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableObject<std::shared_ptr<Appointment>> { impl.getNextAppointmentChange(std::move(params)) } };
};

template <class TImpl>
concept getNextAppointmentChange = requires (TImpl impl)
{
	{ service::AwaitableObject<std::shared_ptr<Appointment>> { impl.getNextAppointmentChange() } };
};

template <class TImpl>
concept getNodeChangeWithParams = requires (TImpl impl, service::FieldParams params, response::IdType idArg)
{
	{ service::AwaitableObject<std::shared_ptr<Node>> { impl.getNodeChange(std::move(params), std::move(idArg)) } };
};

template <class TImpl>
concept getNodeChange = requires (TImpl impl, response::IdType idArg)
{
	{ service::AwaitableObject<std::shared_ptr<Node>> { impl.getNodeChange(std::move(idArg)) } };
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

} // namespace methods::SubscriptionHas

class Subscription
	: public service::Object
{
private:
	service::AwaitableResolver resolveNextAppointmentChange(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveNodeChange(service::ResolverParams&& params) const;

	service::AwaitableResolver resolve_typename(service::ResolverParams&& params) const;

	struct Concept
	{
		virtual ~Concept() = default;

		virtual void beginSelectionSet(const service::SelectionSetParams& params) const = 0;
		virtual void endSelectionSet(const service::SelectionSetParams& params) const = 0;

		virtual service::AwaitableObject<std::shared_ptr<Appointment>> getNextAppointmentChange(service::FieldParams&& params) const = 0;
		virtual service::AwaitableObject<std::shared_ptr<Node>> getNodeChange(service::FieldParams&& params, response::IdType&& idArg) const = 0;
	};

	template <class T>
	struct Model
		: Concept
	{
		Model(std::shared_ptr<T>&& pimpl) noexcept
			: _pimpl { std::move(pimpl) }
		{
		}

		service::AwaitableObject<std::shared_ptr<Appointment>> getNextAppointmentChange(service::FieldParams&& params) const final
		{
			if constexpr (methods::SubscriptionHas::getNextAppointmentChangeWithParams<T>)
			{
				return { _pimpl->getNextAppointmentChange(std::move(params)) };
			}
			else if constexpr (methods::SubscriptionHas::getNextAppointmentChange<T>)
			{
				return { _pimpl->getNextAppointmentChange() };
			}
			else
			{
				throw std::runtime_error(R"ex(Subscription::getNextAppointmentChange is not implemented)ex");
			}
		}

		service::AwaitableObject<std::shared_ptr<Node>> getNodeChange(service::FieldParams&& params, response::IdType&& idArg) const final
		{
			if constexpr (methods::SubscriptionHas::getNodeChangeWithParams<T>)
			{
				return { _pimpl->getNodeChange(std::move(params), std::move(idArg)) };
			}
			else if constexpr (methods::SubscriptionHas::getNodeChange<T>)
			{
				return { _pimpl->getNodeChange(std::move(idArg)) };
			}
			else
			{
				throw std::runtime_error(R"ex(Subscription::getNodeChange is not implemented)ex");
			}
		}

		void beginSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::SubscriptionHas::beginSelectionSet<T>)
			{
				_pimpl->beginSelectionSet(params);
			}
		}

		void endSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::SubscriptionHas::endSelectionSet<T>)
			{
				_pimpl->endSelectionSet(params);
			}
		}

	private:
		const std::shared_ptr<T> _pimpl;
	};

	Subscription(std::unique_ptr<Concept>&& pimpl) noexcept;

	service::TypeNames getTypeNames() const noexcept;
	service::ResolverMap getResolvers() const noexcept;

	void beginSelectionSet(const service::SelectionSetParams& params) const final;
	void endSelectionSet(const service::SelectionSetParams& params) const final;

	const std::unique_ptr<Concept> _pimpl;

public:
	template <class T>
	Subscription(std::shared_ptr<T> pimpl) noexcept
		: Subscription { std::unique_ptr<Concept> { std::make_unique<Model<T>>(std::move(pimpl)) } }
	{
	}
};

} // namespace graphql::today::object

#endif // SUBSCRIPTIONOBJECT_H
