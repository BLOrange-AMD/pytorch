# DO NOT EDIT! This file was generated by jschema_to_python version 0.0.1.dev29,
# with extension for dataclasses and type annotation.

from __future__ import annotations

import dataclasses
from typing import Optional

from typing_extensions import Literal

from torch.onnx._internal.diagnostics.infra.sarif_om import _location, _property_bag


@dataclasses.dataclass
class Suppression(object):
    """A suppression that is relevant to a result."""

    kind: Literal["inSource", "external"] = dataclasses.field(
        metadata={"schema_property_name": "kind"}
    )
    guid: Optional[str] = dataclasses.field(
        default=None, metadata={"schema_property_name": "guid"}
    )
    justification: Optional[str] = dataclasses.field(
        default=None, metadata={"schema_property_name": "justification"}
    )
    location: Optional[_location.Location] = dataclasses.field(
        default=None, metadata={"schema_property_name": "location"}
    )
    properties: Optional[_property_bag.PropertyBag] = dataclasses.field(
        default=None, metadata={"schema_property_name": "properties"}
    )
    state: Optional[Literal["accepted", "underReview", "rejected"]] = dataclasses.field(
        default=None, metadata={"schema_property_name": "state"}
    )


# flake8: noqa
