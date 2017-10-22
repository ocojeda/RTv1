/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:29:37 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/22 17:20:47 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	xmlSchemaPtr	get_xsd(void)
{
	xmlSchemaPtr			ptr_schema;
	xmlSchemaParserCtxtPtr	ptr_ctxt;

	ptr_schema = NULL;
	ptr_ctxt = xmlSchemaNewParserCtxt(VALIDATOR_XSD);
	xmlSchemaSetParserErrors(ptr_ctxt, (xmlSchemaValidityErrorFunc)NULL,
		(xmlSchemaValidityWarningFunc)NULL, stderr);
	ptr_schema = xmlSchemaParse(ptr_ctxt);
	xmlSchemaFreeParserCtxt(ptr_ctxt);
	return (ptr_schema);
}

void	check_doc(xmlDocPtr	doc)
{
	xmlSchemaPtr			ptr_schema;
	xmlSchemaValidCtxtPtr	ptr_validctxt;
	int						vl_return;

	ptr_schema = get_xsd();
	if (!ptr_schema)
		err_found("Could not open XML Schema");
	ptr_validctxt = xmlSchemaNewValidCtxt(ptr_schema);
	xmlSchemaSetValidErrors(ptr_validctxt,
							(xmlSchemaValidityErrorFunc)NULL,
							(xmlSchemaValidityWarningFunc)NULL, stderr);
	vl_return = xmlSchemaValidateDoc(ptr_validctxt, doc);
	if (vl_return == 0)
		xmlSchemaFreeValidCtxt(ptr_validctxt);
	if (vl_return != 0)
		err_found("Bad XML format");
}