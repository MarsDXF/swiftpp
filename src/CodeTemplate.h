//
//  CodeTemplate.h
//  swiftpp
//
//  Created by Sandy Martel on 2014/09/30.
//  Copyright (c) 2014年 dootaini. All rights reserved.
//

#ifndef H_CodeTemplate
#define H_CodeTemplate

#include "substringref.h"
#include <functional>
#include <deque>

struct CodeTemplateModel
{
	std::function<bool ( const std::string &, std::string & )> resolveName;
	std::function<bool ( const std::string &, int, CodeTemplateModel & )> resolveSection;
};

class CodeTemplate
{
	public:
		CodeTemplate( const substringref &i_tmpl );
	
		void render( const CodeTemplateModel &i_model, const std::function<void (const char *,size_t)> &i_writer );
	
	private:
		substringref _tmpl;
		std::deque<CodeTemplateModel> _context;

		void render( const substringref &i_tmpl, const std::function<void (const char *,size_t)> &i_writer );

		std::string resolveName( const std::string &i_name );
		bool resolveSection( const std::string &i_name, int i_index, CodeTemplateModel &o_model );
};

#endif